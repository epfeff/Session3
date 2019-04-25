/**
 Programming SS 2019 - Problem Set 3
 Exercise 6
 Authors: Elena Pfefferlé, Pascal Schenk
*/
#include <iostream>
#include <cmath>            // for sin
// user defined library
#include "simpson.hpp"
// definitions
# define PI 3.14159265358979323846
# define LAMBDA 2

using namespace std;

// declarations
// integrand
double f(double x);

// integrand object class definition
class f_obj{
  public:
    //constructor declaration
    f_obj(double lbd);
    // overload operator () declaration
    double operator()(double x);
  private:
    // to store the value of lambda, defaults to 1
    double lambda = 1;
};
// f_obj class constructor
f_obj::f_obj (double lbd)
{
  lambda=lbd;
}
// f_obj class operator () function
double f_obj::operator()(double x)
{
  return std::exp(-lambda*x);
}
// integrand function
double f(double x)
{
  return std::exp(-LAMBDA*x);
}

int main(void)
{
  // sets the output precision to 15 digits
  std::cout.precision(15);
  // creates a new object f_obj g
  f_obj  g(LAMBDA);
  // simpson computing parameters declaration
  unsigned bins = 128;
  double a = 0;
  double b = 1;
  // outputs simpson area computing
  std::cout << "simpson with pointer : " << simpson(f, a, b, bins) << endl;
  std::cout << "simpson with object : " << simpson(g, a, b, bins) << endl;
  // outputs answers to questions 6.2
  std::cout << "6.2 : What is this concept ? :" << endl;
  std::cout << "------------------------------" << endl;
  std::cout << "We set the type of simpson() to the type of a & b." << endl << endl;
  std::cout << "6.2 : What happens if you call your function like simpson(0, 1, 128, func obj)? : " << endl;
  std::cout << "----------------------------------------------------------------------------------" << endl;
  std::cout << "it returns 0 because a,b are interpreted as integers." << endl;
  return(0);
}
