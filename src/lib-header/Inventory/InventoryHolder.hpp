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

    // Method to get the number of element in the container.
    int getLength();

    // Pure virtual method for adding a card to the container of card.
    virtual void operator+(const Card& newCard) = 0;

    // Pure virtual method for removing a card from the container of card. 
    virtual void operator-(int n) = 0;
};

#endif