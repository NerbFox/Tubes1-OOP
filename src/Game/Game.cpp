#include "../lib-header/Game/Game.hpp"
#include <iostream> 

Game::Game() : tableCard(), deckCard(), reward(64), countPermainan(1), countRonde(1){
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue.push_back(make_pair(Player(), false));
    }
    playerPointer = &playerQueue.at(0).first;
    playerQueue.at(0).second = true;
}

Game::~Game(){}

void Game::turn(){

}

void Game::nextPlayer() {
    if (!isEveryoneHaveTurn()){

    }
}

void Game::doubleReward(){
    this->reward *= multiplier;
}

void Game::halfReward(){
    this->reward /= multiplier;
}

void Game::reverseOrder() {
}

bool Game::isEveryoneHaveTurn(){
    deque<pair<Player,bool>>::iterator it;
    for (it = playerQueue.begin(); it != playerQueue.end(); ++it){
        if (!it->second) return false
    }
    return true;
}

TableCard Game::getTableCard(){
    return tableCard;
}

DeckCard Game::getTableCard(){
    return deckCard;
}