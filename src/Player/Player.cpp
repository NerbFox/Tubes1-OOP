#include "../lib-header/Player/Player.hpp"
#include "../lib-header/Command/Ability.hpp"
#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Command/Command.hpp"


#include <iostream>

#include "../lib-header/Command/Double.hpp"
#include "../lib-header/Command/Half.hpp"
#include "../lib-header/Command/Next.hpp"

#include "../lib-header/Exception/Exception.hpp"
#include "../lib-header/Ability/Abilityless.hpp"
#include "../lib-header/Ability/Quadruple.hpp"
#include "../lib-header/Ability/Quarter.hpp"
#include "../lib-header/Ability/ReRoll.hpp"
#include "../lib-header/Ability/ReverseDirection.hpp"
#include "../lib-header/Ability/Swap.hpp"
#include "../lib-header/Ability/Switch.hpp"

using namespace std;

// ctor
Player::Player(string _name) : normalCard{}, name{_name}, point{0}, abilityCard{}, allCombo{}, AbilityUsed(false), nextCommand{} { }

// cctor
Player::Player(const Player& other) : name{other.name}, point{other.point}, abilityCard{other.abilityCard}, AbilityUsed{other.AbilityUsed}, nextCommand{}, normalCard{other.normalCard}{
    setAllCombo(other.allCombo);
}

// copy assignment
Player& Player::operator=(const Player& other) {
    name = other.name;
    point = other.point;
    AbilityUsed = other.AbilityUsed;
    abilityCard = other.abilityCard;
    setAllCombo(other.allCombo);
    normalCard = other.normalCard;
    return *this;
}

// dtor
Player::~Player() {
    cout << "dtor player " << name << endl;
    delete abilityCard; 
    delete nextCommand;
}

void Player::setName(const string& newName) {
    name = newName;
}

string Player::getName() const {
    return name;
}

long long Player::getPoint() const {
    return point;
}

void Player::addPoint(long long pointsToAdd) {
    point += pointsToAdd;
}

// set the ability card of the player
void Player::setAbilityCard(Ability *card) {
    abilityCard = card;
}    

// update player's normal card at certain index
void Player::setNormalCard(const Card& card, int index) {
    normalCard.updateAt(card, index);
}

// get player's normal card at certain index
Card Player::getNormalCard(int index) {
    return normalCard.getCards()[index];
}

Ability* Player::getAbilityCard() {
    return abilityCard;
}

// push card to player's normal card

// set all of the combo that the player have
void Player::setAllCombo(const vector<Combo>& _allCombo) {
    for (int i = 0; i < _allCombo.size(); i++) {
        allCombo.push_back(_allCombo[i]);
    }    
} 

// clear the combo that the player has
void Player::clearCombo() {
    allCombo.clear();
}

bool Player::operator>(const Player& otherPlayer) const {
    int temp1 = 0;
    for (int i = 0; i < allCombo.size(); i++) {
        if (allCombo[i].getValue() > temp1) {
            temp1 = allCombo[i].getValue();
        }
    }

    int temp2 = 0;
    for (int i = 0; i < otherPlayer.allCombo.size(); i++) {
        if (otherPlayer.allCombo[i].getValue() > temp1) {
            temp2 = otherPlayer.allCombo[i].getValue();
        }
    }

    return temp1 > temp2;
}

bool Player::operator<(const Player& otherPlayer) const {
    int temp1 = 0;
    for (int i = 0; i < allCombo.size(); i++) {
        if (allCombo[i].getValue() > temp1) {
            temp1 = allCombo[i].getValue();
        }
    }

    int temp2 = 0;
    for (int i = 0; i < otherPlayer.allCombo.size(); i++) {
        if (otherPlayer.allCombo[i].getValue() > temp1) {
            temp2 = otherPlayer.allCombo[i].getValue();
        }
    }

    return temp1 < temp2;
}

void Player::getCommand(Game& game) {
    string enteredCmd;
    cout << "\nMasukkan perintah\n>> ";
    cin >> enteredCmd;

    try {
        if (enteredCmd == "DOUBLE" || enteredCmd == "HALF" || enteredCmd == "NEXT") {
            if (enteredCmd == "DOUBLE") {
                cout << "double masuk\n";
                nextCommand = new Double();
            } else if (enteredCmd == "HALF") {
                nextCommand = new Half();
            } else {
                nextCommand = new Next();
            } 
            // nextCommand->action(game);
            cout << endl << name << " melakukan "<< enteredCmd << "!\n"; 
            // delete nextCommand;
        } else if (enteredCmd == "ABILITYLESS" || enteredCmd == "QUADRUPLE" || enteredCmd == "QUARTER" || 
                enteredCmd == "RE-ROLL" || enteredCmd == "REVERSE" || enteredCmd == "SWAP" || enteredCmd == "SWITCH") {
                        if (isAbilityUsed()) {
                            throw InvalidInputException("Kartu telah digunakan!");
                        } else if (enteredCmd != abilityCard->getType()) {
                            throw InvalidInputException("Kamu tidak memiliki kartu tersebut!");
                        } else {
                            abilityCard->action(game);
                            setAbilityUsed(true);
                            cout << endl << name << " melakukan "<< enteredCmd << "!\n";
                        }
                    }
        else {
            throw InvalidInputException("input command salah/tidak ada");
        }
    } catch (const InvalidInputException &err) {
        cout << err.what() << endl;
        getCommand(game);
    }
}

bool Player::isAbilityUsed() const {
    return  AbilityUsed;
}

void Player::setAbilityUsed(bool _AbilityUsed) {
    AbilityUsed = _AbilityUsed;
}

// int main() {
//     cout << "test";
//     return 0;
// }