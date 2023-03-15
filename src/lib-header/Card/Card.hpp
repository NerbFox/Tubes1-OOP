#ifndef CARD_HPP
#define CARD_HPP

#include "BaseCard.hpp"
#include <string>
#include <iostream>
using namespace std;

class Card : public BaseCard {
private:
    int number;         // The number of the card.
    string color;  // The color of the card.
    const int comboId = 1;

public:
    // Constructor
    Card(int number = 0, string color = "");

    // Copy constructor
    Card(const Card& other);

    // Assignment operator
    Card& operator=(const Card& other);

    // Returns the color of the card.
    string getColor() const; 

    // Returns the number of the card.
    int getNumber() const; 

    // Prints the card's number and color to the console.
    void printCard() const;

    // Returns true if the card has no number or color assigned. 
    bool isEmpty() const; 

    // Compute the value of the card;
    void computeValue();
};



#endif