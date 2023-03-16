#include "../lib-header/Card/Card.hpp"
// #include "BaseCard.cpp"
using namespace std;
#include "colors.hpp"
#include <iomanip>

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
    cout << "Kartu " << number << " " << color << endl;
    // print the card number with color
    // cout << "-------" << endl;
    // cout << "|     |" << endl;
    // cout << "|  " << number << "  |" << endl;
    // cout << "|     |" << endl;
    // cout << "-------" << endl;

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
    
    cout << ".---------." << endl;
    cout << "|" << setw(9) << left << number << "|" << endl;
    for (int i=0; i<4; i++) {
        cout << "|         |" << endl;
    }
    cout << "|" << setw(9) << right << number << "|" << endl;
    cout << "'---------'" << endl;

    cout << RESET;
}

void Card::printCard(Card card2) const
{
    // print the card
    cout << "1. Kartu " << number << " " << color << endl;
    cout << "2. Kartu " << card2.number << " " << card2.color << endl;
    string c1, c2;
    
    if (color == "merah")
    {
        c1 = RED;
    }
    else if (color == "hijau")
    {
        c1 = GREEN;
    }
    else if (color == "kuning")
    {
        c1 = YELLOW;
    }
    else if (color == "biru")
    {
        c1 = BLUE;
    }

    if (card2.color == "merah")
    {
        c2 = RED;
    }
    else if (card2.color == "hijau")
    {
        c2 = GREEN;
    }
    else if (card2.color == "kuning")
    {
        c2 = YELLOW;
    }
    else if (card2.color == "biru")
    {
        c2 = BLUE;
    }
    // print the card number with color
    // cout << "-------" << endl;
    // cout << "|     |" << endl;
    // cout << "|  " << number << "  |" << endl;
    // cout << "|     |" << endl;
    // cout << "-------" << endl;

    cout << c1 << ".---------." << "\t" << c2 << ".---------." << endl;
    cout << c1 << "|" << setw(9) << left << number << "|" << "\t" << c2 << "|" << setw(9) << left << card2.number << "|" << endl;
    for (int i=0; i<4; i++) {
        cout << c1 << "|         |" << "\t" << c2 << "|         |" << endl;
    }
    cout << c1 << "|" << setw(9) << right << number << "|" << "\t" << c2 << "|" << setw(9) << right << card2.number << "|" << endl;
    cout << c1 << "'---------'" << "\t" << c2 << "'---------'" << endl;

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
