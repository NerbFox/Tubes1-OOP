#ifndef HALF_HPP
#define HALF_HPP

#include "Command.hpp"
using namespace std;

class Half : public Command {
    friend class Game;

    private :
        string type;
        const int multipiler = 2;

    public :
        Half();
        ~Half(); 
        void action(Game game);
};  


#endif