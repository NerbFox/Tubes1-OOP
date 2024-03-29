#ifndef BASE_CARD_HPP
#define BASE_CARD_HPP
#include <map>
#include <string>

using namespace std;

class BaseCard {
protected:
    double value; // The value of the card.
    map<string, int> colorCode;

public:
    // Constructor
    BaseCard(double _value = 0.0);

    // Copy constructor
    BaseCard(const BaseCard& other);

    // Returns the value of the card.
    double getValue() const; 

    // Returns map for color code
    map<string, int> getColorCode() const;

    // Computes the value of the card, to be implemented by derived classes.
    virtual void computeValue() = 0; 
    
    // Compares the value of two cards and returns true if the value of this card is less than the other card.
    bool operator<(const BaseCard&) const; 
    
    // Compares the value of two cards and returns true if the value of this card is greater than the other card.
    bool operator>(const BaseCard&) const; 
    
    // Compares the value of two cards and returns true if the value of this card is equal to the other card.
    bool operator==(const BaseCard&) const; 
};


#endif