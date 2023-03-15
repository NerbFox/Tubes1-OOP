#include "lib-header/Game/Game.hpp"
using namespace std;

int main() {
  try {
    Game gameState;
    int n = gameState.deckCard.getLength();
    gameState.deckCard.shuffleCard();
    gameState.fetchDeckOption();



  } catch (const char* err) {
    cout << err;
  }
}