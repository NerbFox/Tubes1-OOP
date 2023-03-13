#include "../lib-header/Ability/Quadruple.hpp"

using namespace std;

Quadruple::Quadruple() {
    // Do nothing
    Ability::setType("Quadruple");
}

Quadruple::~Quadruple() {
    // Do Nothing
}

// Action
void Quadruple::action(Game game) {
    game.reward *= FACTORQ; 
}