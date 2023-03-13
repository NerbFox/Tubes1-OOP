#include "../lib-header/Ability/ReRoll.hpp"

ReRoll::ReRoll() {
    Ability::setType("ReRoll");
}

// action
void ReRoll::action(Game game) {
    // Throw 2 cards from player's main deck and take 2 cards again
    // if (game.playerPointer->getMainDeck().getCardCount() < 2) {
    //     cout << "You don't have enough card to use this ability" << endl;
    //     return;
    // }
    // else {
    int index = 0;
    
    // take 2 cards from the player's main deck
    Card card1 = game.playerPointer.first->getNormalCard(0);
    Card card2 = game.playerPointer.first->getNormalCard(1);
    // take 2 cards from the deck and put it to the player's main deck
    game.playerPointer.first->setNormalCard(game.deckCard.getTopCard(), 0);
    game.deckCard-1;
    game.playerPointer.first->setNormalCard(game.deckCard.getTopCard(), 1);
    game.deckCard-1;

    // put the card back to the deck
    game.deckCard+(card1);
    game.deckCard+(card2);
    
    // game.deckCard+(game.deckCard.getTopCard());
    // }
    // game.playerPointer->takeCard(2);
}
