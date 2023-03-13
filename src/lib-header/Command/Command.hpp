#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../Game/Game.hpp"

class Command {
    private : 
    public : 
        virtual void action(Game) = 0;
        virtual void action(Player) = 0;
};  


#endif