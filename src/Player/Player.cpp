#include "../lib-header/Player/Player.hpp"
#include <iostream>

using namespace std;

Player::Player() : name {"noName"}, point{0}, abilityCard{}, allCombo{}, power{0} { }

string Player::getName() const {
    return name;
}

void Player::setName(const string& newName) {
    name = newName;
}

long long Player::getPoint() const {
    return point;
}

void Player::addPoint(long long pointsToAdd) {
    point += pointsToAdd;
}

bool Player::operator>(const Player& otherPlayer) const {
    return power > otherPlayer.getPower();
}

bool Player::operator<(const Player& otherPlayer) const {
    return power < otherPlayer.getPower();
}

void Player::getCommand() {
    string command;
    cout << "Please input command\n>>";
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