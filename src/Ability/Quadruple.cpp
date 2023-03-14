#include "../lib-header/Ability/Quadruple.hpp"

using namespace std;

Quadruple::Quadruple() {
    // Do nothing
    Ability::setType("QUADRUPLE");
}

Quadruple::~Quadruple() {
    // Do Nothing
}

// Action
void Quadruple::action(Game game) {
    game.playerPointer.first->setAbilityUsed(true);
    game.reward *= FACTORQ; 
}