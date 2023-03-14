#ifndef NEXT_HPP
#define NEXT_HPP

#include "Command.hpp"
using namespace std;

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