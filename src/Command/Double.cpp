#include "../lib-header/Command/Double.hpp"
#include "../lib-header/Game/Game.hpp"

// ctor
Double::Double(){
    setTypeCommand(false);
}

Double::~Double(){

}

void Double::action(Game game){
    game.reward *= multipiler;
    game.nextPlayer();
}