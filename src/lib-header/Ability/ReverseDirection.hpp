#ifndef REVERSE_DIRECTION_HPP
#define REVERSE_DIRECTION_HPP

#include "../Command/Ability.hpp"

class ReverseDirection : public Ability {
    private:
        bool reverseOn;
        int pivot;
    public:
        ReverseDirection();
        ~ReverseDirection();

        void FirstReverseStage();
        void SecondReverseStage();
        void action(Game game);
};

#endif