#include "InventoryHolder.hpp"
#include "../Card/Card.hpp"
#include <iostream>
#include <queue>

using namespace std;

#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

class DeckCard : public InventoryHolder<queue<Card>>{
  public:
    // ctor, isi dengan 52 kartu yang ada di poker
    DeckCard();

    // Shuffle card in deck.
    void shuffleCard();

    // Method to get the first index in card (index 0).
    Card getTopCard();

    // Method for adding a card to the container of card.
    void operator+(const Card& newCard);

    // Method to remove card at the first index. 
    void operator-(const Card& removedCard);
};  


#endif