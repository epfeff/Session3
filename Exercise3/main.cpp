/**
 Programming SS 2019 - Problem Set 3
 Exercise 3
 Author: Elena Pfefferlé
 Contact: eapfefferle@gmail.com
*/
#include <iostream>
#include <cmath>
// user defined library
#include "libintegrate.h"

# define PI 3.14159265358979323846

using namespace std;
// declarations

// integrands
double f(double x);
double g(double x);
// simpson function
double simpson(double (*f)(double), double a, double b, double n);

int main(void)
{
  double b = simpson(f, 0, PI, 100);
  std::cout << b << endl;
  double c = simpson(g, 0, 1, 100);
  std::cout << c << endl;
}
// integrand 1
double f(double x) {
  double y = 0;
  y = sin(x);
  return y;
}
// integrand 2
double g(double x) {
  double y = 0;
  y = x-(x*x);
  return y;
}
