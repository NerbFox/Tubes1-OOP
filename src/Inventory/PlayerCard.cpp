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
    // throw exception("Player card is not found")
  }  
}

void PlayerCard::updateAt(Card updateCard, int index) {
  cardContainer[index] = updateCard;
}

array<Card, 2> PlayerCard::getCards() const {
  return cardContainer;
}


// // assignment operator. 
// PlayerCard& PlayerCard::operator=(const PlayerCard& other) {
//   cardContainer[0] = other.cardContainer[0];
//   cardContainer[1] = other.cardContainer[1];
//   return *this;
// }  