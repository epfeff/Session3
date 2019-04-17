#include <iostream>

using namespace std;

int main(void)
{
  enum Z2 { Plus, Minus };

  Z2 operator* (Z2 a, Z2 b);

  Z2 p = Plus, m = Minus;
  Z2 r = p*m;
}

// Output a reversed normalized sequence
void printReverse(double array[], int size) {
  std::cout << "Reverse normalized sequence: [";
  for (int i = size-1; i>=0; i--) {
    std::cout << array[i];
    if (i != 0) {
      std::cout << ", " ;
    }
  }
  std::cout << "]" << endl;
}
