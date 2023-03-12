#include <iostream>
#include "../lib-header/Card/Card.hpp"

#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP

using namespace std;

template <size_t N>
class InventoryHolder {
  protected:
    // An array of card lists of size N.
    array<Card, N> arrayCard;

  public:
    // ctor
    InventoryHolder();

    // Method to print the contents of the array of card.
    void printArrayCard();

    // Method to return a card at certain index.
    Card getCard(int index);

    // Pure virtual method for adding a card to the array of card.
    virtual void operator+(const Card& newCard) = 0;

    // Pure virtual method for removing a card from the array of card. 
    virtual void operator-(const Card& removedCard) = 0;
};

#endif