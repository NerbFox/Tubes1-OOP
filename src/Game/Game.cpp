#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Exception/Exception.hpp"
#include <random>
#include <algorithm>

Game::Game() : tableCard(), deckCard(), reward(64), countPermainan(0), countRonde(0), abilityCardQueue{}{
    fetchPlayerName();
    playerPointer.first = playerQueue[0].first;
    playerPointer.second = 0;
    playerQueue[0].second = true;
    setAbilityCard();
    cout << "\nGame is starting...\n";
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
        if (countRonde == 1){
            setAbilityCard();
        }
        // Kondisional untuk round selain 2
    } else {
        if (isHaveWinner() != -1){
            printLeaderboard();
        } else {
            countRonde = 0;
            countPermainan++;
        }
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
    cout << "Leaderboard";
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
    cout << "====================Candy Kingdom Card Game====================\n";
    cout << "Masukkan nama untuk semua player. Tiap player harus memiliki nama yang berbeda\n";
    for (int i = 0; i < MAX_PLAYER; i++){
        valid = false;
        string input;

        while (!valid){ 
            try{
                cout << "Masukkan nama untuk player-" << i+1 << ": ";
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
        }
        catch (const NotIntegerException& err) {
            cout << err.what() << endl;
        }
    }
    if (input == "0") {
        // shuffle deck card and ability card
        shuffleDeckCard();        
        shuffleAbilityCard();

    } else if (input == "1") {
        // fetch deck card from file
        string fildeir;
        cout << "Letakkan file pada folder test\nMasukkan nama file (contoh: test1.txt)\n>> ";
        cin >> fildeir;
        deckCard.fetchCardFromFile(fildeir);

        // shuffle ability card
        shuffleAbilityCard();
    }
    // distribute deck cards to players
    distributeDeckCard();
}

void Game::shuffleAbilityCard(){
    // Create a vector of cards from the queue
    std::vector<Ability*> cards;
    while (!abilityCardQueue.empty()) {
        cards.push_back(abilityCardQueue.front());
        abilityCardQueue.pop_front();
    }

    // Shuffle the vector using the Fisher-Yates algorithm
    random_device rd;
    mt19937 gen(rd());
    for (int i = cards.size() - 1; i > 0; --i) {
        uniform_int_distribution<> dis(0, i);
        int j = dis(gen);
        swap(cards[i], cards[j]);
    }

    // Add the shuffled cards back to the queue
    for (const auto& card : cards) {
        abilityCardQueue.push_front(card);
    }
}

void Game::shuffleDeckCard(){
    this->deckCard.shuffleCard();
}

void Game::distributeAbilityCard(){
    // distribute ability cards to player
    // this->shuffleAbilityCard(); 
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

void Game::startGame() {
    fetchDeckOption();
    distributeDeckCard();
    // belum set semua player ability = false ketika mulai game baru

    cout << "Memulai Permainan ke-" << countPermainan+1 << endl;
    for (int i = 0; i < MAX_ROUND; i++) {
        cout << "\nRound : " << countRonde + 1;
        cout << "  -  Poin Hadiah : " << reward << "\n\n";
        if (countRonde == 2) {
            cout << "Kartu ability telah dibagikan!\n";
            distributeAbilityCard();
        }
        
        for (int j = 0; j < MAX_PLAYER; j++) {
            cout << "Giliran " << playerPointer.first->getName();
            cout << "  -  Poin Kamu : " << playerPointer.first->getPoint() << endl;
            cout << "Kamu memiliki kartu berikut:\n";
            cout << "1. ";
            playerPointer.first->getNormalCard(0).printCard();
            cout << "2. ";
            playerPointer.first->getNormalCard(1).printCard();
            if (countRonde >= 1) {
                cout << "Ability : " << playerPointer.first->getAbilityCard()->getType() << " - " ;
                if (playerPointer.first->isAbilityUsed()){
                    cout << "bisa digunakan\n";
                } else {
                    cout << "tidak bisa digunakan\n";
                }
            }
            playerPointer.first->getCommand(*this);
            nextPlayer();
        }
    }



}