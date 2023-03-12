#ifndef BASE_CARD_HPP
#define BASE_CARD_HPP

class BaseCard {
private:
    float value; // The value of the card.

public:
    // Returns the value of the card.
    float getValue(); 

    // Computes the value of the card, to be implemented by derived classes.
    virtual void computeValue() = 0; 
    
    // Compares the value of two cards and returns true if the value of this card is less than the other card.
    bool operator<(const BaseCard&); 
    
    // Compares the value of two cards and returns true if the value of this card is greater than the other card.
    bool operator>(const BaseCard&); 
    
    // Compares the value of two cards and returns true if the value of this card is equal to the other card.
    bool operator==(const BaseCard&); 
};


#endif