#ifndef SWAP_HPP
#define SWAP_HPP
#include "../Command/Ability.hpp"

class Swap : public Ability {
    public:
        Swap();
        ~Swap();
        void action(Game game);
};

#endif