#include "../lib-header/Inventory/DeckCard.hpp"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

// ctor, isi dengan 52 kartu yang ada di poker
DeckCard::DeckCard() : InventoryHolder{} {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; i++) {
      string color;
      switch (i) {
        case 0:
          color = "hijau";
          break;
        case 1:
          color = "kuning";
          break;
        case 2:
          color = "merah";
          break;
        case 3:
          color = "biru";
          break;                
        default:
          color = "none";
          // throw exception("warna tidak ditemukan");              
          // untuk sementara gini dulu karena belum ada implementasi exception
      }
      cardContainer.push(Card(((i+1)*(j+1)) % 13 + 1, color));
    }
  }
}

// Method to shuffle card in deck.
void DeckCard::shuffleCard() {
  // Create a vector of cards from the queue
  std::vector<Card> cards;
  while (!cardContainer.empty()) {
    cards.push_back(cardContainer.front());
    cardContainer.pop();
  }

  // Shuffle the vector using the Fisher-Yates algorithm
  random_device rd;
  mt19937 gen(rd());
  for (int i = cards.size() - 1; i > 0; --i) {
      uniform_int_distribution<> dis(0, i);
      int j = dis(gen);
      swap(cards[i], cards[j]);
  }

  // Add the shuffled cards back to the queue
  for (const auto& card : cards) {
    cardContainer.push(card);
  }
}

// Method to get the first index in card (index 0).
Card DeckCard::getTopCard() {
  Card res = cardContainer.front();
  cardContainer.pop();
  return res;
}

    // Method for adding a card to the container of card.
void DeckCard::operator+(const Card& newCard){
  cardContainer.push(newCard);
}

    // Method to remove card at the first index. 
void DeckCard::operator-(const Card& removedCard){
  cardContainer.pop();
}

// int main () {
//   cout << "test";
//   return 0;
// }