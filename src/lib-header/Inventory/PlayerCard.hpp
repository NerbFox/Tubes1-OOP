#include "../lib-header/Inventory/InventoryHolder.hpp"
#include <iostream>

#ifndef PLAYER_CARD_HPP
#define PLAYER_CARD_HPP

class PLayerCard {
  public:
    // ctor, isi dengan 52 kartu yang ada di poker
    PLayerCard();

    // method for adding a card to the array of card at the end of the deck.
    void operator+(const Card& newCard);

    // method for removing a card from the array of card. 
    void operator-(const Card& removedCard);
};  


#endif