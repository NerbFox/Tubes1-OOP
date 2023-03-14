#include "../lib-header/Card/BaseCard.hpp"
#include <iostream>
using namespace std;

// Constructor
BaseCard::BaseCard(float _value) : value{_value} {
  colorCode["hijau"] = 0;
  colorCode["biru"] = 1;
  colorCode["kuning"] = 2;
  colorCode["merah"] = 3;
}

// Copy constructor
BaseCard::BaseCard(const BaseCard& other) : value{other.value} { }

// Returns the value of the card.
float BaseCard::getValue() const {
  return value;
} 

// Compares the value of two cards and returns true if the value of this card is less than the other card.
bool BaseCard::operator<(const BaseCard& other) const {
  return value < other.value;
} 

// Compares the value of two cards and returns true if the value of this card is greater than the other card.
bool BaseCard::operator>(const BaseCard& other) const {
  return value > other.value;
} 

// Compares the value of two cards and returns true if the value of this card is equal to the other card.
bool BaseCard::operator==(const BaseCard& other) const {
  return value == other.value;
} 

// int main() {
//   cout << "test";
//   return 0;
// }