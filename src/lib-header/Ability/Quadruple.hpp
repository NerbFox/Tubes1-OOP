#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP
#include "../lib-header/Command/Ability.hpp"

class Quadruple : public Ability {
    private:
        const int FACTORQ = 4;
    public:
        Quadruple();
        ~Quadruple();
};  


#endif