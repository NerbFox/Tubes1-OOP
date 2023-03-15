#include "../lib-header/Ability/ReRoll.hpp"
#include "../lib-header/Game/Game.hpp"

ReRoll::ReRoll() {
    Ability::setType("RE-ROLL");
}

// action
void ReRoll::action(Game& game) {
    // Throw 2 cards from player's main deck and take 2 cards again
    game.playerPointer.first->setAbilityUsed(true);
    int index = 0;
    
    // take 2 cards from the player's main deck
    Card card1 = game.playerPointer.first->getNormalCard(0);
    Card card2 = game.playerPointer.first->getNormalCard(1);
    
    // take 2 cards from the deck and put it to the player's main deck
    game.playerPointer.first->setNormalCard(game.deckCard.getTopCard(), 0);
    game.deckCard-1;
    game.playerPointer.first->setNormalCard(game.deckCard.getTopCard(), 1);
    game.deckCard-1;

    // put the card back to the deck
    game.deckCard+(card1);
    game.deckCard+(card2);

    // print the result
    cout << "Kamu berhasil mendapatkan : " << endl; 
    cout << "1. ";
    game.playerPointer.first->getNormalCard(0).printCard();
    cout << "2. ";
    game.playerPointer.first->getNormalCard(1).printCard();
    cout << endl;
    cout << "Tekan enter untuk melanjutkan" << endl;
    string input;
    getline(cin, input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
