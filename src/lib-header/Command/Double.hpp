#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "../Command/Command.hpp"

class Double : public Command {
    friend class Game;

    private :
        string type;
        const int multipiler = 2;

    public : 
        Double();
        ~Double();
        void action(Game game);
};  

#endif