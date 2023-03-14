#include "../lib-header/Inventory/InventoryHolder.hpp"
#include "../lib-header/Card/Card.hpp"
// #include "../Card/Card.cpp"
#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

// ctor
template <typename T>
InventoryHolder<T>::InventoryHolder() : cardContainer{} {}

template <typename T>
int InventoryHolder<T>::getLength() {
  return cardContainer.size();
}

template class InventoryHolder<vector<Card>>;
template class InventoryHolder<queue<Card>>;
template class InventoryHolder<array<Card, 2>>;