#include <iostream>
#include <vector>
#include "InventoryHolder.hpp"
#include "../Card/Card.hpp"

#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

class TableCard : public InventoryHolder<vector<Card>> {
  public:
    // ctor
    TableCard();

    // method for adding a card to an empty slot.
    void operator+(const Card& newCard);

    // Method to remove the first card from container n times.
    void operator-(int n);
};  


#endif