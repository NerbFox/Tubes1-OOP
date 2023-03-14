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

    // method for removing a card for a specific index. 
    void operator-(int n);

    // method for update the container at certain index. 
    void updateAt(Card updateCard, int index);

    // get the cards in the container.
    array<Card, 2> getCards() const;

    // assignment operator. 
    // PlayerCard& operator=(const Card& PlayerCard);    
};  


#endif