/**
 Programming SS 2019 - Problem Set 3
 Exercise 3
 Author: Elena Pfefferlé
 Contact: eapfefferle@gmail.com
*/
#include <iostream>
#include <cmath>            // to use sin
// user defined library
#include "simpson/simpson.hpp"

# define PI 3.14159265358979323846

using namespace std;

// integrands
double f(double x);
double g(double x);

int main(void)
{
  // sets terminal precision to 15 digits for good measure
  std::cout.precision(15);
  std::cout << "Testing with sin(x) 0 to PI, 100 bins:" << endl;
  double b = simpson(f, 0, PI, 100);
  std::cout << b << endl;
  std::cout << "Testing with x(1-x) 0 to 1, 100 bins:" << endl;
  double c = simpson(g, 0, 1, 100);
  std::cout << c << endl;
}

/**
    Returns sin of x

*/
double f(double x) {
  double y = 0;
  y = sin(x);
  return y;
}
/**
    Returns x(x-1)

*/
double g(double x) {
  double y = 0;
  y = x-(x*x);
  return y;
}
