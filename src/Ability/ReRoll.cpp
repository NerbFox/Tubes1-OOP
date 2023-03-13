#include "../lib-header/Ability/ReRoll.hpp"

ReRoll::ReRoll() {
    Ability::setType("ReRoll");
}

// action
void ReRoll::action(Game game) {
    // Throw 2 cards from player's main deck and take 2 cards again
    // game.playerPointer->throwCard(2);
    // game.playerPointer->takeCard(2);
}
