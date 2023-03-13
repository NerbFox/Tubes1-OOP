#include "../lib-header/Game/Game.hpp"
#include <iostream> 


Game::Game() : tableCard(), deckCard(), reward(64), countPermainan(1), countRonde(1){
    for (int i = 0; i < MAX_PLAYER; i++){
        playerQueue.push_back(make_pair(Player(), false));
    }
    playerPointer = &playerQueue[0];
}

Game::~Game(){}

void Game::turn(){

}

void Game::nextPlayer() {
    if (!isEveryoneHaveTurn()){
        playerPointer
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
    } else {
        if (resolveWinner() != -1){
            printStandings();
        } else {
            countRonde = 0;
            countPermainan++;
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

int Game::isHaveWinner(){
    for (int idx = 0; idx < MAX_PLAYER; idx++){
        if (playerQueue[idx].first.getPoint() >= MAX_POINT) return idx;
    }
    return -1; // default invalid
}

void Game::printStandings(int pivot){
    vector<Player> result;
    for (int i = 0; i < MAX_PLAYER; i++){
        
        for (int i = 0; i < result.size(); i++){
            if (result.size() == 0 || result[i])
        }
    }
}

int main() {
    cout << "test";

    return 0;
}