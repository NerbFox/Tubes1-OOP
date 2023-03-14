#ifndef QUARTER_HPP
#define QUARTER_HPP
#include "../Command/Ability.hpp"

class Quarter : public Ability {
    private:
        const int DEVISORQ = 4;
        friend class Game;
    public:
        Quarter();
        ~Quarter();
        void action(Game game);
};

#endif