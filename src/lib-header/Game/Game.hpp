#ifndef GAME_HPP
#define GAME_HPP

#include <deque>
#include <iostream>
#include <unordered_set>
#include "../Player/Player.hpp"
#include "../Inventory/TableCard.hpp"
#include "../Inventory/DeckCard.hpp"
#include "../Command/Ability.hpp"
#include "../Ability/ReRoll.hpp"
#include "../Ability/Switch.hpp"
#include "../Ability/Swap.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/Abilityless.hpp"
#include "../Ability/ReverseDirection.hpp"
#include <limits>

using namespace std;

class Game {
    friend class Command;
    friend class Ability;
    friend class ReRoll;
    friend class Switch;
    friend class Swap;
    friend class Quadruple;
    friend class Quarter;   
    friend class Abilityless; 
    friend class Double;
    friend class Half;
    friend class Next;
    friend class ReverseDirection;
    
    private :
        deque<pair<Player*,bool>> playerQueue;
        TableCard tableCard;

        long long reward;
        int countPermainan;
        int countRonde;
        deque<Ability*> abilityCardQueue;

        pair<Player*,int> playerPointer; 

        const int MAX_PLAYER = 7;
        const int MAX_ROUND = 6;
        const long long MAX_POINT = 4294967296; //2 ^ 32         

    public : 
        DeckCard deckCard;
        // Ctor
        Game();

        // dtor
        ~Game();

        // start game
        void startGame();

        // Geser pointer player ke player lain sesuai RR 
        void nextPlayer();

        // Ganti round, round count bertambah 1
        void nextRound();

        // Melakukan pengecekan untuk menentukan pemenang
        int isHaveWinner();

        // Mencetak hasil kelasemen akhir permainan
        void printLeaderboard(); 

        bool isEveryoneHaveTurn();

        // Mengambil Table Card yang ada
        TableCard getTableCard();

        // Mengambil Deck Card 
        DeckCard getDeckCard(); 

        // get max player
        int getMaxPlayer();

        // set ability card kepada player
        void setAbilityCard();

        // set all ability card players 
        void setConditionAbilityCardPlayer(bool);

        // set abilityUsed to a certain index of playerQueue
        void setAbilityUsedPlayer(int, bool);

        // reset all combo player
        void resetAllComboPlayer();
        
        // get index player pointer
        int getIndexPlayerPointer();

        // fetch player name
        void fetchPlayerName();
        
        // fetch deck sort option
        void fetchDeckOption();

        // shuffle ability card
        void shuffleAbilityCard();

        // shuffle deck card
        void shuffleDeckCard();

        // distribute ability card
        void distributeAbilityCard();

        // distribute deck card
        void distributeDeckCard();

        // get round from  
        int getRound();

        // print an ascii art
        void splashScreen();

        // Resolve winner after 7 rounds (1 game)
        void resolveWinner();
};  

// P2 P3 P4 P5 P6 P7 P1 <-

// P4 P3 P2 P1 P7 P6 P5

// P3 P2 P1 P7 P6 P5 P4 <-

// P3 P4 P5 P6 P7 P1 P2

#endif