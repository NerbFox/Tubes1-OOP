#include <iostream>
#include "../Card/Card.hpp"

#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP

using namespace std;

template <typename T>
class InventoryHolder {
  protected:
    // A generic container for cards.
    T cardContainer;

  public:
    // ctor
    InventoryHolder();

    // Pure virtual method for adding a card to the container of card.
    virtual void operator+(const Card& newCard) = 0;

    // Pure virtual method for removing a card from the container of card. 
    virtual void operator-(const Card& removedCard) = 0;
};

#endif