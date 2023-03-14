#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "Command.hpp"

using namespace std;

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