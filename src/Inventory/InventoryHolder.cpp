#include "../lib-header/Inventory/InventoryHolder.hpp"
#include <iostream>

using namespace std;

template <size_t N>
void InventoryHolder<N>::printArrayCard() {
  for (int i = 0; i < N; i++) {
    std::cout << i+1". " << arrayCard[i].printCard() << endl;
  }    
}

template <size_t N>
Card InventoryHolder<N>::getCard(int index) {
  return arrayCard[index];
}

// template <size_t N>
// void InventoryHolder<N>::operator+(const Card& newCard) {
//   for (int i = 0; i < N; i++) {
//     if (arrayCard[i].getColor() == NULL) {
//       arrayCard[i] = newCard;
//       break;
//     }

//     if (i == N - 1) throw exception("Card is full");
//     // Buat sekarang baru throw kyk gini, nunggu kelas exception
    
//   }  
// }

// template <size_t N>
// void InventoryHolder<N>::operator-(Card& card) {
//   for (int i = 0; i < N; i++) {
//     if (arrayCard[i].getColor() != NULL) {
//       card = arrayCard[i];
//       arrayCard[i] = Card();
//       break;
//     }

//     if (i == N - 1) throw exception("Card is empty");
//     // Buat sekarang baru throw kyk gini, nunggu kelas exception
//   }  
// }