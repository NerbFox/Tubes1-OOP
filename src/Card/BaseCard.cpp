#include "../lib-header/Card/BaseCard.hpp"

    // Returns the value of the card.
float BaseCard::getValue() {
  return value;
} 

// Compares the value of two cards and returns true if the value of this card is less than the other card.
bool BaseCard::operator<(const BaseCard& other) {
  return value < other.value;
} 

// Compares the value of two cards and returns true if the value of this card is greater than the other card.
bool BaseCard::operator>(const BaseCard& other) {
  return value > other.value;
} 

// Compares the value of two cards and returns true if the value of this card is equal to the other card.
bool BaseCard::operator==(const BaseCard& other) {
  return value == other.value;
} 