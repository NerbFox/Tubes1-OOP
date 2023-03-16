#include "lib-header/Game/Game.hpp"

// template to get max from array
template <typename T>
T getMax(vector<T> Container)
{
  typename vector<T>::iterator it = Container.begin(); // Use "typename" to specify that vector<T>::iterator is a type
  T max = *it;
  for (it = Container.begin(); it != Container.end(); it++)
  {
    if (*it > max)
    {
      max = *it;
    }
  }
  return max; // Return the value, not the dereferenced iterator
}

// template <typename T, class Kelas>
// T getMax(Kelas<T> Container)
// {
//   typename Kelas<T>::iterator it = Container.begin(); // Use "typename" to specify that vector<T>::iterator is a type
//   T max = *it;
//   for (it = Container.begin(); it != Container.end(); it++)
//   {
//     if (*it > max)
//     {
//       max = *it;
//     }
//   }
//   return max; // Return the value, not the dereferenced iterator
// }

int main()
{
  // int arr[] = {1, 2, 3, 4, 5};
  // cout << getMax<int *, int>(arr);
  // // vector
  // vector<int> vec = {1, 2, 3, 4, 5};
  // cout << getMax(vec);
  try {
    Game gameState;
    
    gameState.startGame();


    cout << "exiting...\n";
  } catch (const char* err) {
    cout << err;
  }
}