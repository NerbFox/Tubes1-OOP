#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP
#include "../Command/Ability.hpp"

class Quadruple : public Ability {
    private:
        const int FACTORQ = 4;
        friend class Game;
    public:
        Quadruple();
        ~Quadruple();
        void action(Game game);
};  


#endif