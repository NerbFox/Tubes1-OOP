#include "../lib-header/Command/Double.hpp"

// ctor
Double::Double(){
    setTypeCommand(false);
}

Double::~Double(){

}

void Double::action(Game game){
    game.reward *= multipiler;
}