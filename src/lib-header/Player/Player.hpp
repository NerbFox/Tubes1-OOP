#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "../Command/Command.hpp"
#include "../Command/Ability.hpp"
#include "../Card/Combo.hpp"
#include "../Inventory/TableCard.hpp"

using namespace std;

class Player {
private:
    string name;                  // player's name
    long long point;              // player's current points
    const int CARD_LEN = 2;       // the number of card in the player's hand
    Ability abilityCard;          // the player's ability card
    vector<Combo> allCombo;       // a vector containing all of the player's combos
    int power;                    // the player's current power (nilai combo paling tinggi yang dia punya)

public:
    // returns the player's name
    string getName() const;                      
    
    // sets the player's name to the given string
    void setName(const string& newName);         
    
    // returns the player's current point total
    long long getPoint() const;                       

    // adds the given number of points to the player's total
    void addPoint(long long pointsToAdd);            
    
    // returns true if this player's power is greater than the other player's
    bool operator>(const Player& otherPlayer) const;  
    
    // returns true if this player's power is less than the other player's
    bool operator<(const Player& otherPlayer) const;  
    
    // request command input from the user and process it
    void getCommand();      
    
    // computes the player's current power based on the cards at hand and on the table
    void computePower(const TableCard& tableCard);    
    
    // returns the player's current power
    int getPower() const;                             
};

#endif