#include "../lib-header/Inventory/DeckCard.hpp"
#include "../lib-header/Exception/Exception.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <set>

using namespace std;

// ctor, isi dengan 52 kartu yang ada di poker
DeckCard::DeckCard() : InventoryHolder{} {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      string color;
      // cout << "i: "<< i << endl;
      // cout << "j: "<< j << endl;
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
          throw "color is not found";              
      }
      cardContainer.push(Card(((i+1)*(j+1)) % 13 + 1, color));
    }
  }
}

// baca dari file
void DeckCard::fetchCardFromFile(const string filedir) {
  ifstream input, cek;
  string line, warna, num;


  // VALIDASI PERTAMA : cek jumlah kartu
  cek.open("../test/" + filedir + ".txt");
  int count = 0;
  while (getline(cek, line)) count++;
  if (count != 52) {
    cek.close();
    throw InvalidInputException("jumlah kartu pada file " + to_string(count) + ", seharusnya 52");
  } 
  cek.close();

  set<pair<string,int>> cardTaken;
  input.open("../test/" + filedir + ".txt");
  while(count > 0){
    input >> num;
    input >> warna;

    // VALIDASI KEDUA : cek warna
    if (warna == "hijau" || warna == "kuning" || warna == "biru" || warna == "merah"){
      // VALIDASI KETIGA : cek angka
      if (stoi(num) > 0 && stoi(num) < 14){
        // VALIDASI KEEMPAT : cek Duplikat
        pair<string,int> temp = make_pair(warna,stoi(num));
        if (cardTaken.count(temp) == 0){
          cardContainer.push(Card(stoi(num), warna));
          cardTaken.insert(temp);
          count--;
        }
        else {
          throw InvalidInputException("Kartu " + warna + "-" + num + "Duplikat");
        }
      }
      else {
        throw InvalidInputException("tidak ada kartu bernomor : " + num);
      }
    }
    else {
      throw InvalidInputException("tidak ada kartu berwarna : " + warna);
    }
  }
  input.close();
  // pertama2 pop dulu semua
  // trs masukin ke container dengan cara cardContainer.push(angka, warna));
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
  return cardContainer.front();
}

// Method for adding a card to the container of card.
void DeckCard::operator+(const Card& newCard){
  cardContainer.push(newCard);
}

// Method to remove the first card from container n times.
void DeckCard::operator-(int n){
  if (n > cardContainer.size()) {
    throw "the number of cards that wanted to be removed is bigger than the number of cards in the deck card\n";
  }

  for (int i = 0; i < n; i++) {
    cardContainer.pop();
  }
}

void DeckCard::clearQueue() {
  while (!cardContainer.empty()) {
    cardContainer.pop();
  }
}

// int main () {
//   cout << "test";
//   return 0;
// }