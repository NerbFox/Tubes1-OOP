#include "../lib-header/Player/Player.hpp"
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
void Player::setAbilityCard(const Ability& card) {
    abilityCard = card;
}    

// update player's normal card at certain index
void Player::setNormalCard(const Card& card, int index) {
    normalCard.updateAt(card, index);
}

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
    return power > otherPlayer.getPower();
}

bool Player::operator<(const Player& otherPlayer) const {
    return power < otherPlayer.getPower();
}

void Player::getCommand() {
    string command;
    cout << "Please input command\n>> ";
    cin >> command;
    
    // Masih nunggu command class untuk diimplementasi
}

void Player::computePower(const TableCard& tableCard) {
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