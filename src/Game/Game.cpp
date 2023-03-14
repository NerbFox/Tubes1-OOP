#include "../lib-header/Game/Game.hpp"

Game::Game() : tableCard(), deckCard(), reward(64), countPermainan(1), countRonde(1){
    bool valid;
    unordered_set<string> nameTaken;
    cout << "Masukkan nama untuk semua player. Tiap player harus memiliki nama yang berbeda\n";
    for (int i = 0; i < MAX_PLAYER; i++){
        valid = false;
        string input;

        cout << "Masukkan nama untuk player-" << i+1 << ": ";
        while (!valid){ 
            try{
                getline(cin, input);
                if (nameTaken.count(input) > 0) {
                    throw NamaDuplikatException(input);
                }   
                else if (input.length() > 20){
                    throw NamaPanjangException(input.length());
                }
                else { 
                    playerQueue.push_back(make_pair(Player(input), false));
                    nameTaken.insert(input);
                    valid = true;
                }
            }
            catch (const NamaDuplikatException &err){
                cout << err.what() << endl;
                i--;
            }
            catch (const NamaPanjangException &err){
                cout << err.what() << endl;
                i--;
            }
        }
    }
    playerPointer.first = &playerQueue[0].first;
    playerPointer.second = 0;
    playerQueue[0].second = true;
}

Game::~Game(){
    for (int i = 0; i < MAX_PLAYER; i++){
        delete abilityCardQueue[i];
    }
    playerQueue.clear();
    abilityCardQueue.clear();
}

void Game::turn(){

}

void Game::nextPlayer() {
    if (!isEveryoneHaveTurn()){
        int i = 0;
        while (playerQueue[i].second){
            i++;
        }
        playerPointer.first = &playerQueue[i].first;
        playerPointer.second = i;
    }
    else {
        Game::nextRound();
    }
}

void Game::nextRound(){
    if (countRonde < MAX_ROUND){
        pair<Player,bool> temp;
        temp = playerQueue.front();
        playerQueue.pop_front();
        playerQueue.push_back(temp);

        for (int i = 1; i < MAX_PLAYER; i++){
            playerQueue[i].second = false;
        }

        playerPointer.first = &playerQueue[0].first;
        playerPointer.second = 0;

        countRonde++;
        // kondisional untuk round 2
            // Random methodnya udh ada blom ya ? 
        if (countRonde == 2){
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

void Game::reverseOrder() {
    deque<pair<Player,bool>> copy; 
    for (int i = playerPointer.second + 1; i - playerPointer.second <= MAX_PLAYER; i++){
        copy.push_front(playerQueue.at(i%MAX_PLAYER));
    }
    this->playerQueue.swap(copy);
}

bool Game::isEveryoneHaveTurn(){
    deque<pair<Player,bool>>::iterator it;
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
        if (playerQueue[idx].first.getPoint() >= MAX_POINT) return idx;
    }
    return -1; // default invalid
}

void Game::printLeaderboard(){
    cout << "Leaderboard";
    for (int i = 0; i < MAX_PLAYER; i++){
        cout << i+1 << ". " << playerQueue[i].first.getName() << " : " << playerQueue[i].first.getPoint() << endl;   
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
    Ability* abilityCard4 = new ReversDirection();
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

    // Distribute ability card to player
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue[i].first.setAbilityCard(abilityCardQueue[i]);
    }

}

// set all ability card player
void Game::setConditionAbilityCardPlayer(bool condition){
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue[i].first.setAbilityUsed(condition);
    }
}

// set abilityUsed player
void Game::setAbilityUsedPlayer(int idx, bool condition){
    int indexPemain = this->getIndexPlayerPointer();
    playerQueue[idx].first.setAbilityUsed(condition);
    if (idx < 0 || idx > MAX_PLAYER){
        throw IndexOutOfBoundsException(idx, MAX_PLAYER);
    }
    if (idx==indexPemain) {
        throw IndexNotValidException(idx) ;
    }
}

// get index player pointer
int Game::getIndexPlayerPointer(){
    int i = 0;
    for (auto currentPair : this->playerQueue) {
        if (currentPair.first.getName() != this->playerPointer.first->getName()) {
            i++;
        } else {
            return i;
        }
    }
}

// int main() {
//     cout << "test";

//     return 0;
// }