#ifndef GAME_HPP
#define GAME_HPP

#include <queue>
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

        Player* playerPointer; 

        const int MAX_PLAYER = 7;
        const int MAX_ROUND = 6;
        const long long MAX_POINT = 4294967296; //2 ^ 32


    public : 
        // Ctor

        // start game
        void startGame();

        // Prosedur player untuk melakukan permainan
        void turn();

        // Geser pointer player ke player lain sesuai RR 
        void nextPlayer();

        // Menambahkan reward menjadi 2 kali sebelumnya
        void doubleReward();

        // Mengurangi reward menjadi 1/2 kali sebelumnya
        void halfReward();

        // Melakukan reverse urutan
        void reverseOrder();

        // Melakukan pengecekan untuk menentukan pemenang
        void resolveWinner();
        
};  

// P2 P3 P4 P5 P6 P7 P1
// P3 P4 P5 P6 P7 P1 P2
// P4 P5 P6 P7 P1 P2 P3

// P4 P5 P6 P7 P1 P2 P3
// P3 P2 P1 P7 P6 P5 P4

#endif