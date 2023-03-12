#include "../lib-header/Inventory/TableCard.hpp"
#include <iostream>

// ctor
TableCard::TableCard() : InventoryHolder{} {}

// method for adding a card to an empty slot.
void TableCard::operator+(const Card& newCard) {
  cardContainer.push_back(newCard);
}

// method for removing a specific card the container. 
void TableCard::operator-(const Card& removedCard) {
  for (int i = 0; i < cardContainer.size(); i++) {
    if ( i == cardContainer.size() - 1 ) {
      // throw exception("Card not in container")
    }
    if (cardContainer[i] == removedCard) {
      cardContainer.erase(cardContainer.begin() + i);
      break;
    }
  }
}