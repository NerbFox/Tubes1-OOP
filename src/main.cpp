#include "lib-header/Game/Game.hpp"
using namespace std;

// template to get max from array
// template <class T1, class Type>
// T1 getMax(T1 Container){
//   T1::iterator it = Container.begin();
//   Type max = *it;
//   for (it = Container.begin(); it != Container.end(); it++){
//     if (*it > max){
//       max = *it;
//     }
//   }
//   return max;
// }


int main() {
  // int arr[] = {1, 2, 3, 4, 5};
  // cout << getMax<int*, int>(arr);
  try {
    Game gameState;
    
    
    gameState.startGame();



    cout << "exiting...\n";
  } catch (const char* err) {
    cout << err;
  }
}