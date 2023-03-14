#include "../lib-header/Game/Game.hpp"

Game::Game() : tableCard(), deckCard(), reward(64), countPermainan(1), countRonde(1){
    bool valid;
    unordered_set<string> nameTaken;
    for (int i = 0; i < MAX_PLAYER; i++){
        valid = false;
        string input;
        
        cout << "Masukkan nama player-" << i+1 << ": ";
        try{
            getline(cin, input);
            if (nameTaken.count(input) > 0) {
                throw "";
            }   
            else if (input.length() > 20){
                throw "";
            }
            else { 
                playerQueue.push_back(make_pair(Player(input), false));
                nameTaken.insert(input);
            }
        }
        catch (const ){
        }
        catch (const ){
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
        if (resolveWinner() != -1){
            printStandings();
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

void Game::printStandings(){
    vector<Player> result;
    for (int i = 0; i < MAX_PLAYER; i++){
        
        for (int i = 0; i < result.size(); i++){
            if (result.size() == 0 || result[i])
        }
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
        playerQueue[i].setAbilityCard(abilityCardQueue[i]);
    }

}

// set all ability card player
void Game::setConditionAbilityCardPlayer(bool condition){
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue[i].setAbilityUsed(condition);
    }
}

// int main() {
//     cout << "test";

//     return 0;
// }