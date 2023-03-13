#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP
#include "../lib-header/Command/Ability.hpp"

class ReRoll : public Ability {
    private:
    public:
        ReRoll();
        ~ReRoll();
        // action
        void action(Game game);
};  


#endif