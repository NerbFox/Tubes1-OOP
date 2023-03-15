#include <iostream>
using namespace std;

class B;

class A {
  public:
  void changeB(B& c);
};

class B {
  public:
    int x ;
    A objA;
    B() : x {3} {};
    void changeNow() {
      objA.changeB(*this);
    }

  friend class A;
};

void A::changeB(B& c) {
  c.x = 2;
}

int main () {
  B objB;
  cout << objB.x << endl;
  objB.changeNow();
  cout << objB.x << endl;
  cout << false;

}