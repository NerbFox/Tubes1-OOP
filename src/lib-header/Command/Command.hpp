#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../Game/Game.hpp"

class Command {
    private : 
    public : 
        friend virtual void action(Game game) = 0;
};  


#endif