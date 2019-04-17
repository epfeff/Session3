#include <iostream>

using namespace std;

// declaration
enum Z2 { Plus, Minus };
Z2 operator * (Z2 a, Z2 b);
std::ostream& operator<<(std::ostream& os, Z2 a);
template<class T> T operator* (T a, Z2 b);
template<class T> T operator* (Z2 a, T b);

int main(void)
{

  Z2 p = Plus, m = Minus;
  Z2 r = p*m;

  std::cout << r << endl;

  signed int a = 0;
  signed int b = 0;

  a = -2 * p;
  b = m * 2;

  std::cout << 2*p << endl;
  std::cout << b << endl;

  int n = 0;
  std::cin >> n;
}

Z2 operator * (Z2 a, Z2 b)
{
  if (a == b){
    return Plus;
  } else {
    return Minus;
  }
}

std::ostream& operator<<(std::ostream& os, Z2 a)
{
    if (a == Plus){
      os << "Plus";
    } else {
      os << "Minus";
    }
    return os;
}

template<class T> T operator* (T a, Z2 b)
{
  if (a > 0){
    if (b > 0) {
      return +1;
    } else {
      return -1;
    }
  } else {
    if (b > 0) {
      return +1;
    } else {
      return -1;
    }
  }
}

template<class T> T operator* (Z2 a, T b)
{
  if (b > 0){
    if (a == Plus) {
      return +1;
    } else {
      return -1;
    }
  } else {
    if (a == Plus) {
      return -1;
    } else {
      return +1;
    }
  }
}
