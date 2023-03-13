#ifndef SWITCH_HPP
#define SWITCH_HPP
#include "../lib-header/Command/Ability.hpp"

class Switch : public Ability {
    /*menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain. Harus 
    bertukar milik sendiri dengan pemain lain. Tidak boleh ke 2 pemain lain.
    */

    private:
    public:
        Switch();
        ~Switch();
        // action
        void action(Game game);
};

#endif