#ifndef NEXT_HPP
#define NEXT_HPP

#include "../Command/Command.hpp"

class Next : public Command {
    friend class Game;

    private :
        string type;

    public :
        Next(); 
        ~Next(); 
        void action(Game game);
};

#endif