#ifndef REVERSE_DIRECTION_HPP
#define REVERSE_DIRECTION_HPP

#include "../Command/Ability.hpp"

class ReverseDirection : public Ability {
    friend class Game;
    private:
        int pivot;
    public:
        ReverseDirection();
        ~ReverseDirection();
        void action(Game& game);
};

#endif