#include "../lib-header/Command/Half.hpp"
#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Exception/Exception.hpp"

// ctor
Half::Half(){
    setTypeCommand(false);
}

Half::~Half(){

}

void Half::action(Game& game){
    if (game.reward > 1){
        game.reward /= multipiler;
    }
    else {
        throw InvalidInputException("Poin telah mencapai minimum (1 poin)");
    }
}