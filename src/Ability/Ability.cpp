#include "../lib-header/command/Ability.hpp"
#include "../lib-header/Game/Game.hpp"
#include "../lib-header/Exception/Exception.hpp"

#include <iostream>
using namespace std;

Ability::Ability() {
    /*Kartu Ability akan diberikan ke pemain pada ronde kedua. Pemain dapat menggunakan ability dan 
    melihat kartu ability pada giliran kedua. Kartu ability hanya ada tujuh sehingga setiap 
    permainan pasti akan habis dibagi ke semua pemain. Kartu ability hanya bisa dipakai sekali per 
    permainan dan bisa juga tidak digunakan. Terdapat kekuatan diantaranya.
    */
}

Ability::Ability(const Ability& otherAbility) {
    type = otherAbility.type;
}

Ability& Ability::operator=(const Ability& otherAbility) {
    type = otherAbility.type;
    return *this;
}

Ability::~Ability() {
}

// getter
string Ability::getType() {
    return type;
}

// setter
void Ability::setType(string type) {
    this->type = type;
}