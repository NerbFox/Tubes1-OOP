#include "../lib-header/Inventory/TableCard.hpp"
#include <iostream>

// ctor
TableCard::TableCard() : InventoryHolder{} {}

// method for adding a card to an empty slot.
void TableCard::operator+(const Card& newCard) {
  cardContainer.push_back(newCard);
}

// Method to remove the first card from container n times.
void TableCard::operator-(int n) {
  if (n > cardContainer.size()) {
    throw "number of cards will be removed is bigger than the number of cards in the container";
  }

  for (int i = 0; i < n; i++) {
    cardContainer.erase(cardContainer.begin());
  }
}