#ifndef NON_ABILITY_HPP
#define NON_ABILITY_HPP

#include "Command.hpp"

class Double : public Command {
    private : 
    public : 
        void action(Game game);
};  

class Next : public Command {
    private : 
    public : 
        void action(Game game);
};  

class Half : public Command {
    private : 
    public : 
        void action(Game game);
};  


#endif