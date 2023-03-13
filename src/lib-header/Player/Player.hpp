#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "../Command/Command.hpp"
#include "../Command/Ability.hpp"
#include "../Card/Combo.hpp"
#include "../Inventory/TableCard.hpp"
#include "../Inventory/PlayerCard.hpp"

using namespace std;

class Player {
protected:
    string name;                  // player's name
    long long point;              // player's current points
    PlayerCard normalCard;        // player's normal card
    Ability abilityCard;          // player's ability card
    vector<Combo> allCombo;       // a vector containing all of the player's combos
    int power;                    // the player's current power (nilai combo paling tinggi yang dia punya)

public:
    // ctor
    Player(string _name = "", long long _point = 0, int _power = 0);

    // cctor
    Player(const Player& other);

    // cctor
    Player& operator=(const Player& other);

    // sets the player's name to the given string
    void setName(const string& newName);         

    // returns the player's name
    string getName() const;                      
    
    // returns the player's current point total
    long long getPoint() const;                       

    // adds the given number of points to the player's total
    void addPoint(long long pointsToAdd);        

    // set the ability card of the player
    void setAbilityCard(const Ability& card);    

    // update player's normal card at certain index
    void setNormalCard(const Card& card, int index);

    // set all of the combo that the player have
    void setAllCombo(const vector<Combo>& _allCombo); 

    // clear the combo that the player has
    void clearCombo();
    
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