#include "../lib-header/Card/Card.hpp"
// #include "BaseCard.cpp"
using namespace std;

// Constructor
Card::Card(int number, string color) : BaseCard{}, number(number), color(color) { computeValue();}

// Copy constructor
Card::Card(const Card& other) : BaseCard{other} ,number(other.number), color(other.color) {}

// Assignment operator
Card& Card::operator=(const Card& other) {
    value = other.value;
    number = other.number;
    color = other.color;
    return *this;
}

string Card::getColor() const {
    return color;
}

int Card::getNumber() const {
    return number;
}

void Card::printCard() const {
    cout << "Number: " << number << ", Color: " << color << std::endl;
}

bool Card::isEmpty() const {
    return (number == 0 && color.empty());
}

void Card::computeValue() {
    // Belum selesai
}

// int main() {
//   cout << "test";
//   return 0;
// }