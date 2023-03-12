#include "../lib-header/Inventory/InventoryHolder.hpp"
#include <iostream>

using namespace std;

#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

class DeckCard : InventoryHolder<52>{
  public:
    // Method to shuffle card in deck.
    void shuffleCard();

    // Pure virtual method for adding a card to the array of card.
    Card getTopCard();

    
    // Pure virtual method for adding a card to the array of card.
    void operator+(const Card& newCard);

    // Pure virtual method for removing a card from the array of card. 
    void operator-(const Card& removedCard);
};  


#endif