#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>

class Game;

class Command {
    friend class Game;
    
    private : 
        bool typeCommand; // ability = true, non-ability = false

    public : 
        Command();
        ~Command();
        // getter 
        bool getTypeCommand();
        // setter
        void setTypeCommand(bool);
        // action
        virtual void action(Game &) = 0;
        // virtual void action(Player) = 0;
};  


#endif