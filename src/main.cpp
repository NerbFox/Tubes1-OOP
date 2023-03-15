#include "lib-header/Game/Game.hpp"
using namespace std;

int main() {
  try {
    Game gameState;
    
    gameState.startGame();


    cout << "exiting...\n";
  } catch (const char* err) {
    cout << err;
  }
}