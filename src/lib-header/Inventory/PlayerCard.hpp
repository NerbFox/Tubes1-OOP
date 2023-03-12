#include "InventoryHolder.hpp"
#include "../Card/Card.hpp"
#include <iostream>
#include <array>

#ifndef PLAYER_CARD_HPP
#define PLAYER_CARD_HPP

class PlayerCard : public InventoryHolder<array<Card, 2>> {
  public:
    // ctor
    PlayerCard();

    // method for adding a card to an empty slot.
    void operator+(const Card& newCard);

    // method for removing a specific card the container. 
    void operator-(const Card& removedCard);
};  


#endif