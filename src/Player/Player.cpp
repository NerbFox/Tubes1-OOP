#include "../lib-header/Player/Player.hpp"
#include "../lib-header/Command/Ability.hpp"
#include <iostream>

using namespace std;

// ctor
Player::Player(string _name, long long _point, int _power) : normalCard{}, name{_name}, point{_point}, power{_power}, abilityCard{}, allCombo{} { }

// cctor
Player::Player(const Player& other) : name{other.name}, point{other.point}, power{other.power}, abilityCard{other.abilityCard} {
    setAllCombo(other.allCombo);
}

// cctor
Player& Player::operator=(const Player& other) {
    name = other.name;
    point = other.point;
    power = other.power;
    abilityCard = other.abilityCard;
    setAllCombo(other.allCombo);
    return *this;
}

// dtor
Player::~Player() {delete abilityCard;}

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

void Player::getCommand() {
    string command;
    cout << "Please input command\n>> ";
    cin >> command;
    
    // Masih nunggu command class untuk diimplementasi
}

void Player::computePower(const TableCard& tableCard) const {
    // Masih nunggu combo class untuk diimplementasi
    // Masih nunggu generic function buat dapetin value tertinggi
}

int Player::getPower() const {
    return power;
}

// int main() {
//     cout << "test";
//     return 0;
// }