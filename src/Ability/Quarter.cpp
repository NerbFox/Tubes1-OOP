#include "../lib-header/Ability/Quarter.hpp"
#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Exception/Exception.hpp"

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
    if (game.reward > 1){
        game.playerPointer.first->setAbilityUsed(true);
        game.reward /= DEVISORQ;
    }
    else {
        throw InvalidInputException("Poin telah mencapai minimum (1 poin)");
    }
}