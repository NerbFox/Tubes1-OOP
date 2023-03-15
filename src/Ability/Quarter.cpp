#include "../lib-header/Ability/Quarter.hpp"
#include "../lib-header/Game/Game.hpp"

using namespace std;

Quarter::Quarter() {
    // Do Nothing
    Ability::setType("QUARTER");
}

Quarter::~Quarter() {
    // Do Nothing
}

// Action
void Quarter::action(Game& game) {
    game.playerPointer.first->setAbilityUsed(true);
    game.reward /= DEVISORQ;
}