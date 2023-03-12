#include "../lib-header/Inventory/PlayerCard.hpp"
#include <iostream>

// ctor
PlayerCard::PlayerCard() : InventoryHolder{} {}

// method for adding a card to an empty slot.
void PlayerCard::operator+(const Card& newCard) {
  if (cardContainer[0].isEmpty()) {
    cardContainer[0] = newCard;
  } else if (cardContainer[1].isEmpty()) {
    cardContainer[1] = newCard;
  } else {
    // throw exception("Player card is full")
  }
}

// method for removing a specific card the container. 
void PlayerCard::operator-(const Card& removedCard) {
  if (cardContainer[0] == removedCard) {
    cardContainer[0] = Card();
  } else if (cardContainer[1] == removedCard) {
    cardContainer[1] = Card();
  } else {
    // throw exception("Player card is not found or empty")
  }  
}