#include "../lib-header/Inventory/InventoryHolder.hpp"
#include "../lib-header/Card/Card.hpp"
// #include "../Card/Card.cpp"
#include <iostream>

using namespace std;

// ctor
template <typename T>
InventoryHolder<T>::InventoryHolder() : cardContainer{} {}

template <typename T>
int InventoryHolder<T>::getLength() {
  return cardContainer.size();
}