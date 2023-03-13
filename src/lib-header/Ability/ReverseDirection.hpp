#ifndef REVERSE_DIRECTION_HPP
#define REVERSE_DIRECTION_HPP

#include "../Command/Ability.hpp"
#include "../Game/Game.hpp"

class ReversDirection : public Ability {
    private:
        bool reverseOn;
        int pivot;
    public:
        ReversDirection();
        ~ReversDirection();

        void FirstReverseStage();
        void SecondReverseStage();
};

#endif