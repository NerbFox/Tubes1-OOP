#include "../lib-header/Inventory/DeckCard.hpp"
#include <iostream>

using namespace std;

// ctor, isi dengan 52 kartu yang ada di poker
DeckCard::DeckCard() : InventoryHolder() {
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
          // throw exception("warna tidak ditemukan");              
          // untuk sementara gini dulu karena belum ada implementasi exception
      }
      // arrayCard[(i+1)*(j+1)] = Card(((i+1)*(j+1)) % 13 + 1, color);
      // untuk sementara gini dulu karena belum ada implementasi card
    }
  }
}

// Method to shuffle card in deck.
void DeckCard::shuffleCard() {
  
}

// Method to get the most top index in card (index 0).
Card DeckCard::getTopCard() {
  return arrayCard.getCard(0);
}

// method for adding a card to the array of card at the end of the deck.
void DeckCard::operator+(const Card& newCard){
  for (int i = 0; i < arrayCard.size(); i++) {
    if (i == arrayCard.size() - 1) {} 
    // throw exception("Card is full");
    // Buat sekarang baru throw kyk gini, nunggu kelas exception    
    
    if (arrayCard[i].isEmpty()) {
      arrayCard[i] = newCard;
      break;
    }
  }  
}

// method for removing a card from the array of card. 
void DeckCard::operator-(const Card& removedCard){
  for (int i = 0; i < arrayCard.size(); i++) {
    if (i == arrayCard.size() - 1) {} 
    // throw exception("Card is not found");
    // Buat sekarang baru throw kyk gini, nunggu kelas exception    
    
    if (arrayCard[i] == removedCard) {
      for (int j = i; j < arrayCard.size() - 1; j++) {
        arrayCard[j] = arrayCard[j+1];  
      }
      arrayCard[arrayCard.size() - 1] = Card();
      break;
    }
  }  
}