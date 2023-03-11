#include "../lib-header/Game/Game.hpp"
#include <iostream> 

Game::Game() : tableCard(), deckCard() {

}

Game::~Game(){
    delete [] playerState;
}