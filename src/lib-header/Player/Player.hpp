#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "../Card/Combo.hpp"
#include "../Inventory/TableCard.hpp"
#include "../Inventory/PlayerCard.hpp"

using namespace std;

class Game;
class Ability;
class Command;

class Player {
protected:
    string name;                  // player's name
    long long point;              // player's current points
    PlayerCard normalCard;        // player's normal card
    Ability *abilityCard;         // player's ability card
    Combo combinations;           // An object containing all of the player's combos
    bool AbilityUsed;             // true if the player has used his ability card
    Command *nextCommand;

public:
    // ctor
    Player(string _name = "");

    // cctor
    Player(const Player& other);

    // cctor
    Player& operator=(const Player& other);

    // dtor
    ~Player();

    // getter
    // returns the player's name
    string getName() const;                      
    // returns the player's current point total
    long long getPoint() const;                       
    // pop player's normal card at certain index
    Card getNormalCard(int index);
    // get all player's normal card
    PlayerCard getAllNormalCard() const;
    // request command input from the user and process it
    void getCommand(Game& game);
    Ability* getAbilityCard();
    // bool isAbilityUsed
    bool isAbilityUsed() const;
    // get combinations object
    Combo getCombinations() const;
    
    
    // setter
    // setter isAbilityUsed
    void setAbilityUsed(bool _isAbilityUsed);            
    // sets the player's name to the given string
    void setName(const string& newName);         
    // set the ability card of the player
    void setAbilityCard(Ability *card);    
    // update player's normal card at certain index
    void setNormalCard(const Card& card, int index);
    // set all of the combo that the player have
    void setCombinations(const Combo& _combinations); 


    // Methods
    // adds the given number of points to the player's total
    void addPoint(long long pointsToAdd);        

    // clear the combo that the player has
    void clearCombo();
    
    // returns true if this player's combinations is greater than the other player's
    bool operator>(const Player& otherPlayer) const;  
    
    // returns true if this player's combinations is less than the other player's
    bool operator<(const Player& otherPlayer) const;  
};

#endif