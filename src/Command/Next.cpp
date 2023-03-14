#include "../lib-header/Command/Next.hpp"

// ctor
Next::Next(){
    setTypeCommand(false);
}

Next::~Next(){

}

void Next::action(Game game){
    game.nextPlayer();
}