#include "../lib-header/Ability/Quarter.hpp"

using namespace std;

Quarter::Quarter() {
    // Do Nothing
    Ability::setType("Quarter");
}

Quarter::~Quarter() {
    // Do Nothing
}

// Action
void Quarter::action(Game game) {
    game.playerPointer.first->setAbilityUsed(true);
    game.reward /= DEVISORQ;
}