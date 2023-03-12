#include "../lib-header/Inventory/InventoryHolder.hpp"
#include <iostream>

using namespace std;

#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

class DeckCard : InventoryHolder<52>{
  public:
    // ctor, isi dengan 52 kartu yang ada di poker
    DeckCard();

    // Shuffle card in deck.
    void shuffleCard();

    // Method to get the top index in card (index 0).
    Card getTopCard();

    // method for adding a card to the array of card at the end of the deck.
    void operator+(const Card& newCard);

    // method for removing a card from the array of card. 
    void operator-(const Card& removedCard);
};  


#endif