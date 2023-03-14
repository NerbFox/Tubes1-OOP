#ifndef ABILITY_HPP
#define ABILITY_HPP
#include <string>
#include "../Command/Command.hpp"
#include "../Game/Game.hpp"
#include <iostream>
using namespace std;

class Ability : public Command {
    /*Kartu Ability akan diberikan ke pemain pada ronde kedua. Pemain dapat menggunakan ability dan 
    melihat kartu ability pada giliran kedua. Kartu ability hanya ada tujuh sehingga setiap 
    permainan pasti akan habis dibagi ke semua pemain. Kartu ability hanya bisa dipakai sekali per 
    permainan dan bisa juga tidak digunakan. Terdapat kekuatan diantaranya.
    */
    private:
        string type;
    public:
        Ability();
        Ability(const Ability& otherAbility);
        Ability& operator=(const Ability& otherAbility);
        ~Ability();
        // getter
        string getType();
        // setter
        void setType(string type);
        // action
        virtual void action(Game) = 0;
        // virtual void action(Player) = 0;
};  


#endif