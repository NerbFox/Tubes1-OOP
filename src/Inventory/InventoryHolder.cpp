#include "../lib-header/Inventory/InventoryHolder.hpp"
#include <iostream>

using namespace std;

template <size_t N>
// ctor
InventoryHolder<N>::InventoryHolder() : arrayCard{} {}
  
template <size_t N>
// Method to print the contents of the array of card.
void InventoryHolder<N>::printArrayCard() {
  for (int i = 0; i < N; i++) {
    std::cout << i+1". " << arrayCard[i].printCard() << endl;
  }    
}

template <size_t N>
// Method to return a card at certain index.
Card InventoryHolder<N>::getCard(int index) {
  return arrayCard[index];
}