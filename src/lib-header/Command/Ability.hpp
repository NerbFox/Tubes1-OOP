#ifndef ABILITY_HPP
#define ABILITY_HPP

class Ability {
    private:
        string type;
    public:
        Ability();
        Ability(const Ability& otherAbility);
        Ability& operator=(const Ability& otherAbility);
        ~Ability();
};  


#endif