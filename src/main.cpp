#include "lib-header/Game/Game.hpp"
using namespace std;

int main() {
  try {
    Game gameState;
  } catch (const char* err) {
    cout << err;
  }
}