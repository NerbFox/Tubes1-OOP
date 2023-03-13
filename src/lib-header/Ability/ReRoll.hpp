#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP
#include "../lib-header/Command/Ability.hpp"

class ReRoll : public Ability {
    // Throw 2 cards from player's main deck and take 2 cards again
    private:
    public:
        ReRoll();
        ~ReRoll();
        // action
        void action(Game game);
};  


#endif