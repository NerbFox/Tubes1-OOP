#include "lib-header/Game/Game.hpp"
using namespace std;

int main() {
  try {
    Game gameState;
    int n = gameState.deckCard.getLength();
    gameState.deckCard.shuffleCard();
    for (int i = 0; i < n; i++) {
      cout << i + 1 << ". ";
      gameState.deckCard.getTopCard().printCard();
      gameState.deckCard - 1;
    }



  } catch (const char* err) {
    cout << err;
  }
}