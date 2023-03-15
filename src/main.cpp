#include "lib-header/Game/Game.hpp"
using namespace std;

int main() {
  try {
    Game gameState;
    gameState.fetchDeckOption();


    cout << "exit";
  } catch (const char* err) {
    cout << err;
  }
}