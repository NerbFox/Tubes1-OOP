#ifndef GAME_HPP
#define GAME_HPP

#include <deque>
#include "../Player/Player.hpp"
#include "../Inventory/TableCard.hpp"
#include "../Inventory/DeckCard.hpp"

using namespace std;

class Game {
    friend class Command;
    friend class Ability;
    friend class ReRoll;
    friend class Switch;
    
    private :
        deque<pair<Player,bool>> playerQueue;
        TableCard tableCard;
        DeckCard deckCard;
        long long reward;
        int countPermainan;
        int countRonde;

        pair<Player*,int> playerPointer; 

        const int MAX_PLAYER = 7;
        const int MAX_ROUND = 6;
        const long long MAX_POINT = 4294967296; //2 ^ 32
        const int multiplier = 2;
         


        friend class Command;
        friend class Quadruple;
        friend class Quarter;

    public : 
        // Ctor
        Game();

        // dtor
        ~Game();

        // start game
        void startGame();

        // Prosedur player untuk melakukan permainan
        void turn();

        // Geser pointer player ke player lain sesuai RR 
        void nextPlayer();

        // Ganti round, round count bertambah 1
        void nextRound();

        // Menambahkan reward menjadi 2 kali sebelumnya
        void doubleReward();

        // Mengurangi reward menjadi 1/2 kali sebelumnya
        void halfReward();

        // Melakukan reverse urutan
        void reverseOrder();

        // Melakukan pengecekan untuk menentukan pemenang
        Player resolveWinner();

        bool isEveryoneHaveTurn();

        // Mengambil Table Card yang ada
        TableCard getTableCard();

        // Mengambil Deck Card 
        DeckCard getDeckCard(); 



        
};  

// P2 P3 P4 P5 P6 P7 P1 <-

// P4 P3 P2 P1 P7 P6 P5

// P3 P2 P1 P7 P6 P5 P4 <-

// P3 P4 P5 P6 P7 P1 P2

#endif