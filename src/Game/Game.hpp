#ifndef GAME_HPP
#define GAME_HPP

#include <queue>
#include <iostream>
#include "../Player/Player.hpp"
#include "../Inventory/TableCard.hpp"
#include "../Inventory/DeckCard.hpp"

using namespace std;

class Game {
    private :
        queue<Player> playerState;
        TableCard tableCard;
        DeckCard deckCard;
        int reward;
        int countPermainan;
        int countRonde;

        const int MAX_PLAYER = 7;
        // const int 

    public : 
        Game() : deckCard(), tableCard(){
            for (int i = 0; i < this->MAX_PLAYER; i++) {
                Player *p 
            }
        }
        
    
};  


#endif