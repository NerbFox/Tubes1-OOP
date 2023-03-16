#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Exception/Exception.hpp"
#include "../Card/colors.hpp"
#include <random>
#include <algorithm>

Game::Game() : tableCard(), deckCard(), reward(64), countPermainan(0), countRonde(1), abilityCardQueue{}{
    fetchPlayerName();
    setAbilityCard();
    playerPointer.first = playerQueue[0].first;
    playerPointer.second = 0;
    playerQueue[0].second = true;
    cout << "\nGame is starting...\n";
    std::system("clear");
}

Game::~Game(){
    for (int i = 0; i < MAX_PLAYER; i++){
        delete playerQueue[i].first;
    }
    abilityCardQueue.clear();
    playerQueue.clear();
    abilityCardQueue.clear();
}

void Game::nextPlayer() {
    if (!isEveryoneHaveTurn()){
        int i = 0;
        while (playerQueue[i].second){
            i++;
        }
        playerPointer.first = playerQueue[i].first;
        playerPointer.second = i;
        playerQueue[i].second = true;
    }
    else {
        Game::nextRound();
    }
}

void Game::nextRound(){
    if (countRonde < MAX_ROUND){
        pair<Player*,bool> temp;
        temp = playerQueue.front();
        playerQueue.pop_front();
        playerQueue.push_back(temp);

        for (int i = 1; i < MAX_PLAYER; i++){
            playerQueue[i].second = false;
        }

        playerPointer.first = playerQueue[0].first;
        playerPointer.second = 0;

        countRonde++;
        // kondisional untuk round 2
            // Random methodnya udh ada blom ya ? 

        // Kondisional untuk round selain 2
    } else {
        countRonde = 1;
        countPermainan++;
    }
}

bool Game::isEveryoneHaveTurn(){
    deque<pair<Player*,bool>>::iterator it;
    for (it = playerQueue.begin(); it != playerQueue.end(); ++it){
        if (!it->second) return false;
    }
    return true;
}

TableCard Game::getTableCard(){
    return tableCard;
}

DeckCard Game::getDeckCard(){
    return deckCard;
}

int Game::isHaveWinner(){
    for (int idx = 0; idx < MAX_PLAYER; idx++){
        if (playerQueue[idx].first->getPoint() >= MAX_POINT) return idx;
    }
    return -1; // default invalid
}

void Game::printLeaderboard(){
    cout << "Leaderboard :\n";
    for (int i = 0; i < MAX_PLAYER; i++){
        cout << i+1 << ". " << playerQueue[i].first->getName() << " : " << playerQueue[i].first->getPoint() << endl;   
    }
}


// get max player
int Game::getMaxPlayer(){
    return MAX_PLAYER;
}

// set ability card kepada player
void Game::setAbilityCard(){
    // set ability card
    Ability* abilityCard1 = new Switch();
    Ability* abilityCard2 = new ReRoll();
    Ability* abilityCard3 = new Swap();
    Ability* abilityCard4 = new ReverseDirection();
    Ability* abilityCard5 = new Quarter();
    Ability* abilityCard6 = new Quadruple();
    Ability* abilityCard7 = new Abilityless();    

    abilityCardQueue.push_back(abilityCard1);
    abilityCardQueue.push_back(abilityCard2);
    abilityCardQueue.push_back(abilityCard3);
    abilityCardQueue.push_back(abilityCard4);
    abilityCardQueue.push_back(abilityCard5);
    abilityCardQueue.push_back(abilityCard6);
    abilityCardQueue.push_back(abilityCard7);

}

// set all ability card player
void Game::setConditionAbilityCardPlayer(bool condition){
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue[i].first->setAbilityUsed(condition);
    }
}

// set abilityUsed player
void Game::setAbilityUsedPlayer(int idx, bool condition){
    int indexPemain = this->getIndexPlayerPointer();
    playerQueue[idx].first->setAbilityUsed(condition);
    if (idx < 0 || idx > MAX_PLAYER){
        throw IndexOutOfBoundsException(idx, MAX_PLAYER);
    }
    if (idx==indexPemain) {
        throw IndexNotValidException(idx) ;
    }
}

// get index player pointer
int Game::getIndexPlayerPointer(){
    int i = 0; int indexPemain = 0;
    for (auto currentPair : this->playerQueue) {
        if (currentPair.first->getName() != this->playerPointer.first->getName()) {
            i++;
        } else {
            indexPemain = i;
        }
    }
    return indexPemain;
}

void Game::fetchPlayerName() {
    bool valid;
    unordered_set<string> nameTaken;
    // remove output that have been printed before
    std::system("clear");
    splashScreen();
    cout << "Masukkan nama untuk semua player\n";
    cout << "Setiap player harus memiliki nama yang berbeda\n";
    for (int i = 0; i < MAX_PLAYER; i++){
        valid = false;
        string input;

        while (!valid){ 
            try{
                cout << "Nama player-" << i+1 << ": ";
                getline(cin, input);
                // remove space in the front
                while (input[0] == ' '){
                    input.erase(0,1);
                }
                if (input.empty()){
                    throw EmptyInputException();
                }
                else if (nameTaken.count(input) > 0) {
                    throw NamaDuplikatException(input);
                }   
                else if (input.length() > 20){
                    throw NamaPanjangException(input.length());
                }
                else { 
                    Player *newPlayer = new Player(input);
                    playerQueue.push_back(make_pair(newPlayer, false));
                    nameTaken.insert(input);
                    valid = true;
                }
            }
            catch (const NamaDuplikatException &err){
                cout << err.what() << endl;
            }
            catch (const NamaPanjangException &err){
                cout << err.what() << endl;
            }
            catch (const EmptyInputException &err){
                cout << err.what() << endl;
            }
        }
    }
}

void Game::fetchDeckOption() {
    string input;
    bool valid = false;
    while (!valid) {
        valid = true;
        try {
            cout << "\nUrutan kartu deck ingin diacak atau baca dari file?\n0 : random\n1 : baca dari file\n>> ";
            cin >> input;
            if (input=="0" || input=="1"){
                valid = true;
            }
            else if (input.find_first_not_of("0123456789") != string::npos){
                throw NotIntegerException();
            }
            else{
                throw InvalidInputException("masukkan angka 0 atau 1");
            }       
        }
        catch (const InvalidInputException& err) {
            cout << err.what() << endl;
            valid = false;
        }
        catch (const NotIntegerException& err) {
            cout << err.what() << endl;
            valid = false; 
        }
        if (valid){
            deckCard.clearQueue();
            if (input == "0") {
                // shuffle deck card and ability card
                deckCard = DeckCard();
                shuffleDeckCard();        
                shuffleAbilityCard();

            } else if (input == "1") {
                // fetch deck card from file
                string fildeir;
                cout << "Letakkan file pada folder test\nMasukkan nama file (contoh: test1)\n>> ";
                cin >> fildeir;
                try {

                    deckCard.fetchCardFromFile(fildeir);
                }
                catch (InvalidInputException& e) {
                    valid = false;
                    cout << e.what() << endl;
                }
                catch (...){
                    valid = false;
                    cout << "input tidak valid" << endl;
                }
                // shuffle ability card
                shuffleAbilityCard();
            }
        }
    }
    // distribute deck cards to players
    std::system("clear");
    distributeDeckCard();
}

void Game::shuffleAbilityCard(){
    // cout << "\n\n=====before=====\n";
    vector<Ability *> vec(abilityCardQueue.size());
    int size = abilityCardQueue.size();
    // cout << size;
    for (size_t i = 0; i < size; ++i) {
        vec[i] = abilityCardQueue.front();
        // cout << vec[i]->getType() << endl;        
        abilityCardQueue.pop_front();
    }

    // Shuffle the temporary vector
    random_device rd;
    mt19937 g(rd());
    shuffle(vec.begin(), vec.end(), g);

    // cout << "\n\n=====after=====\n";

    // Push the shuffled elements back into the queue
    for (Ability* ability : vec) {
        // cout << ability->getType() << endl;
        abilityCardQueue.push_back(ability);
    }
}

void Game::shuffleDeckCard(){
    this->deckCard.shuffleCard();
}

void Game::distributeAbilityCard(){
    // distribute ability cards to player
    this->shuffleAbilityCard(); 
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue[i].first->setAbilityCard(abilityCardQueue[i]);
    }
}

void Game::distributeDeckCard(){
    // distribute deck card to player
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue[i].first->setNormalCard(deckCard.getTopCard(), 0);
        deckCard-1;
        playerQueue[i].first->setNormalCard(deckCard.getTopCard(), 1);
        deckCard-1;
    }
}

int Game::getRound() {
    return countRonde;
}

void Game::splashScreen() {
    system("clear");
    cout << MAGENTA;
    cout << "\n\n\n\n";
    cout << "  ______         __       _____  ___    ________    ___  ___       __   ___    __      _____  ___     _______    ________       ______     ___      ___ \n";
    cout << " /\" _  \"\\       /\"\"\\     (\\\"   \\|\"  \\  |\"      \"\\  |\"  \\/\"  |     |/\"| /  \")  |\" \\    (\\\"   \\|\"  \\   /\" _   \"|  |\"      \"\\     /    \" \\   |\"  \\    /\"  |\n";
    cout << "(: ( \\___)     /    \\    |.\\\\   \\    | (.  ___  :)  \\   \\  /      (: |/   /   ||  |   |.\\\\   \\    | (: ( \\___)  (.  ___  :)   // ____  \\   \\   \\  //   |\n";
    cout << " \\/ \\         /' /\\  \\   |: \\.   \\\\  | |: \\   ) ||   \\\\  \\/       |    __/    |:  |   |: \\.   \\\\  |  \\/ \\       |: \\   ) ||  /  /    ) :)  /\\\\  \\/.    |\n";
    cout << " //  \\ _     //  __'  \\  |.  \\    \\. | (| (___\\ ||   /   /        (// _  \\    |.  |   |.  \\    \\. |  //  \\ ___  (| (___\\ || (: (____/ //  |: \\.        |\n";
    cout << "(:   _) \\   /   /  \\\\  \\ |    \\    \\ | |:       :)  /   /         |: | \\  \\   /\\  |\\  |    \\    \\ | (:   _(  _| |:       :)  \\        /   |.  \\    /:  |\n";
    cout << " \\_______) (___/    \\___) \\___|\\____\\) (________/  |___/          (__|  \\__) (__\\_|_)  \\___|\\____\\)  \\_______)  (________/    \\\"_____/    |___|\\__/|___|\n";
    cout << "                                                                                                                                                        \n";
    cout << "          ______         __        _______    ________         _______         __       ___      ___   _______                                          \n";
    cout << "         /\" _  \"\\       /\"\"\\      /\"      \\  |\"      \"\\       /\" _   \"|       /\"\"\\     |\"  \\    /\"  | /\"     \"|                                         \n";
    cout << "        (: ( \\___)     /    \\    |:        | (.  ___  :)     (: ( \\___)      /    \\     \\   \\  //   |(: ______)                                         \n";
    cout << "         \\/ \\         /' /\\  \\   |_____/   ) |: \\   ) ||      \\/ \\          /' /\\  \\    /\\\\  \\/.    | \\/    |                                           \n";
    cout << "         //  \\ _     //  __'  \\   //      /  (| (___\\ ||      //  \\ ___    //  __'  \\  |: \\.        | // ___)_                                          \n";
    cout << "        (:   _) \\   /   /  \\\\  \\ |:  __   \\  |:       :)     (:   _(  _|  /   /  \\\\  \\ |.  \\    /:  |(:      \"|                                         \n";
    cout << "         \\_______) (___/    \\___)|__|  \\___) (________/       \\_______)  (___/    \\___)|___|\\__/|___| \\_______)                                         \n\n\n";
    cout << RESET;
}

void Game::startGame() {
    // reset permainan 
    fetchDeckOption();
    distributeDeckCard();
    setConditionAbilityCardPlayer(false);
    
    // belum set semua player ability = false ketika mulai game baru
    cout << "\n=========================Permainan ke-" << countPermainan+1 << "=========================" << endl;
    for (int i = 0; i < MAX_ROUND; i++) {
        if (countRonde == 2) {
            cout << "\nKartu ability telah dibagikan!\n";
            distributeAbilityCard();
        }
        
        for (int j = 0; j < MAX_PLAYER; j++) {
            cout << "\n===========================Ronde ke-"  << countRonde << "===========================\n";

            cout << "Kartu di meja: \n";
            if (tableCard.getLength() == 0) {
                cout << "Table card kosong\n";
            } else {
                for (int k = 0; k < tableCard.getLength(); k++) {
                    cout << k+1 <<". ";
                    tableCard.getContainerAt(k).printCard();
                }
            }

            cout << "Poin Hadiah : " << reward << "\n\n";            
            cout << "Giliran " << playerPointer.first->getName() << endl;
            cout << "Poin Kamu : " << playerPointer.first->getPoint() << endl;


            cout << "Kamu memiliki kartu berikut:\n";
            // cout << "1. ";
            // playerPointer.first->getNormalCard(0).printCard();
            playerPointer.first->getNormalCard(0).printCard(playerPointer.first->getNormalCard(1));
            // cout << "2. ";
            // playerPointer.first->getNormalCard(1).printCard();

            if (countRonde >= 2) {
                cout << "Ability : " << playerPointer.first->getAbilityCard()->getType() << " - " ;
                if (playerPointer.first->isAbilityUsed()){
                    cout << "tidak bisa digunakan\n";
                } else {
                    cout << "bisa digunakan\n";
                }
            }


            playerPointer.first->getCommand(*this);
            nextPlayer();
            std::system("clear");
        }
        tableCard + deckCard.getTopCard();
        deckCard - 1;
    }



    printLeaderboard();
    int idxWinner = isHaveWinner(); 
    if ( idxWinner == -1) {
        cout << "Belum ada pemenang, game akan diulangi lagi\n";
        startGame();
    } else {
        Player *winner = playerQueue[idxWinner].first;
        cout << "Selamat pemenangnya adalah " << winner->getName() << " dengan skor sebanyak " << winner->getPoint() << endl;   
    }
}