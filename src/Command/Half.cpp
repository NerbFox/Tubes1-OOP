#include "../lib-header/Command/Half.hpp"

// ctor
Half::Half(){
    setTypeCommand(false);
}

Half::~Half(){

}

void Half::action(Game game){
    game.reward /= multipiler;
    game.nextPlayer();
}