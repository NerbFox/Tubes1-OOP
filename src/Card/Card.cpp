#include "../lib-header/Card/Card.hpp"
// #include "BaseCard.cpp"
using namespace std;
#include "colors.hpp"

// Constructor
Card::Card(int number, string color) : BaseCard{}, number(number), color(color) { computeValue(); }

// Copy constructor
Card::Card(const Card &other) : BaseCard{other}, number(other.number), color(other.color) {}

// Assignment operator
Card &Card::operator=(const Card &other)
{
    value = other.value;
    number = other.number;
    color = other.color;
    return *this;
}

// Not equal operator
bool Card::operator!=(const Card &other)
{
    return (number != other.number || color != other.color);
}

string Card::getColor() const
{
    return color;
}

int Card::getNumber() const
{
    return number;
}

void Card::printCard() const
{
    // print the card
    if (color == "merah")
    {
        cout << RED;
    }
    else if (color == "hijau")
    {
        cout << GREEN;
    }
    else if (color == "kuning")
    {
        cout << YELLOW;
    }
    else if (color == "biru")
    {
        cout << BLUE;
    }
    // print the card number with color
    cout << "Kartu " << number << " " << color << endl;
    cout << "-------" << endl;
    cout << "|     |" << endl;
    cout << "|  " << number << "  |" << endl;
    cout << "|     |" << endl;
    cout << "-------" << endl;
    cout << RESET;
}

bool Card::isEmpty() const
{
    return (number == 0 && color.empty());
}

void Card::computeValue()
{
    value = number + colorCode[color] * 0.33;
}
