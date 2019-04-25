/**
 Programming SS 2019 - Problem Set 3
 Exercise 5
 Authors: Elena Pfefferlé, Pascal Schenk
*/
#include <iostream>

using namespace std;
// declaration
enum Z2 { Plus, Minus };
Z2 operator * (Z2 a, Z2 b);
// functions declarations
std::ostream& operator<<(std::ostream& os, Z2 a);
template<class T> T operator* (T a, Z2 b);
template<class T> T operator* (Z2 a, T b);
template<class T> T mypow(T a, unsigned int n);
template<class T> T identity_element();

int main(void)
{

  Z2 p = Plus, m = Minus;
  Z2 r = p*m;
  // some testing
  std::cout << "           r = p*m : " << r << endl;
  std::cout << "            2*Plus : " << 2*Plus << endl;
  std::cout << "           2*Minus : " << 2*Minus << endl;
  std::cout << "           -2*Plus : " << -2*Plus << endl;
  std::cout << "          -2*Minus : " << -2*Minus << endl;
  std::cout << "       Plus * Plus : " << Plus * Plus << endl;
  std::cout << "     Minus * Minus : " << Minus * Minus << endl;
  std::cout << "   Plus * 1 * Plus : " << Plus * Plus * 1 << endl;
  std::cout << "  Plus * -1 * Plus : " << Plus * Plus * -1 << endl;
  std::cout << " Minus * 1 * Minus : " << Minus * Minus * 1 << endl;
  std::cout << "Minus * -1 * Minus : " << Minus * Minus * -1 << endl;
  std::cout << "   mypow -> Plus^5 : " << mypow(Plus,5) << endl;
  std::cout << "  mypow -> Minus^4 : " << mypow(Minus,4) << endl;
  std::cout << "      mypow -> 5^5 : " << mypow(5,2) << endl;
}
// Multiplication operator overload
Z2 operator * (Z2 a, Z2 b)
{
  return (a == b ? Plus : Minus);
}
// Bitwise shift left operator overload
std::ostream& operator<<(std::ostream& os, Z2 a)
{
  // replaces + with Plus and - with Minus
  return (a == Plus ? os << "Plus" : os << "Minus");
}
// Numerical element action on a group (Z2) element
template<class T> T operator* (T a, Z2 b)
{
  // returns Plus if group element is Plus
  return (b == Plus ? a : -a );
}
// group member (Z2) action on a numerical element
template<class T> T operator* (Z2 b, T a)
{
  // uses multiplication
  return a*b;
}
// power function - similar to pow()
template<class T> T mypow(T a, unsigned int n)
{
  // sets the response to 1 - or Plus if a is a group member
  T res(identity_element<T>());
  // computes a^n
  for (unsigned int i = 0; i<n; i++) { res = res*a; }
  return res;
}
// returns 1 for numerical values
template<typename T> T identity_element()
{
  return T(1);
}
// overloads identity_element; returns Plus when arg passed is member of Z2
template<> Z2 identity_element()
{
  return Plus;
}
