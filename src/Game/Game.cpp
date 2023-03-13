#include "../lib-header/Game/Game.hpp"
#include <iostream> 

Game::Game() : tableCard(), deckCard(), reward(64), countPermainan(1), countRonde(1){
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue.push_back(make_pair(Player(), false));
    }
    playerPointer.first = &playerQueue.at(0).first;
    playerPointer.second = 0;
    playerQueue.at(0).second = true;
}

Game::~Game(){}

void Game::turn(){

}

void Game::nextPlayer() {
    if (!isEveryoneHaveTurn()){
        deque<pair<Player,bool>>::iterator it;
        while (it->second){
            ++it;
        }
        
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

int main() {
    cout << "test";

    return 0;
}