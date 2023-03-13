#include "../lib-header/Game/Game.hpp"
#include <iostream> 

Game::Game() : tableCard(), deckCard(), reward(64), countPermainan(1), countRonde(1){
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue.push_back(make_pair(Player(), false));
    }
    playerPointer.first = &playerQueue[0].first;
    playerPointer.second = 0;
    playerQueue[0].second = true;
}

Game::~Game(){}

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
    }
}

void Game::doubleReward(){
    this->reward *= multiplier;
}

void Game::halfReward(){
    this->reward /= multiplier;
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

// get max player
int Game::getMaxPlayer(){
    return MAX_PLAYER;
}

// set ability card kepada player
void Game::setAbilityCard(){
    // Ability abilityCard1;
    // Ability abilityCard2;
    // Ability abilityCard3;
    // Ability abilityCard4;

    // abilityCard1 = ReRoll();
    // abilityCard2 = DoubleReward();
    // ...

    // abilityCardQueue.push_back(abilityCard1);
    // abilityCardQueue.push_back(abilityCard2);
    // ...

    // Distribute ability card to player
    // .. 

}

// set all ability card player
void Game::setConditionAbilityCardPlayer(bool condition){
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue[i].first.setAbilityUsed(condition);
    }
}

// int main() {
//     cout << "test";

//     return 0;
// }