#include "../lib-header/Card/BaseCard.hpp"

// Constructor
BaseCard::BaseCard(float _value = 0.0f) : value{_value} { }

// Copy constructor
BaseCard::BaseCard(const BaseCard& other) : value{other.value} { }

// Assignment operator
BaseCard& BaseCard::operator=(const BaseCard& other) {
  value = other.value;
  return *this;
}

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