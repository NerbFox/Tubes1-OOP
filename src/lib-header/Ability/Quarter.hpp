#ifndef QUARTER_HPP
#define QUARTER_HPP
#include "../lib-header/Command/Ability.hpp"

class Quarter : public Ability {
    private:
        const int DEVISORQ = 4;
    public:
        Quarter();
        ~Quarter();
};

#endif;