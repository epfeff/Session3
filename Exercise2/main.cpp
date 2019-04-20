/**
 Programming SS 2019 - Problem Set 3
 Exercise 2
 Author: Elena Pfefferlé
 Contact: eapfefferle@gmail.com
*/
#include <iostream>
#include <cmath>        // to use sin

# define PI 3.14159265358979323846

using namespace std;
// declarations
double a = 0;
double b = PI;
double n = 0;
double h = 0;
double area = 0;
// integrand function
double f(double x);

int main(void)
{
  // sets output precision to 15 digits for good measure
  std::cout.precision(15);
  // asks user to specifiy amount of bins
  std::cout << "Simpson Integration 0-PI dx sin(x)" << endl;
  std::cout << "Amount of bins: ";
  std::cin >> n;
  h = (b - a)/n;
  // first and last item of the formula
  area = area + f(a);
  area = area + f(b);
  // computes area for each bin
  for (int i = 0; i<n; i++){
    if (i == n-1){
      area = area + 4*f(a+(h/2));
      break;
    }
    area = area + 4*f(a+(h/2));
    area = area + 2*f(a+h);
    a = a + h;
  }
  //final operation
  area = area * h/6;
// outputs results
cout << "Area :" << area << endl;
return(0);
}

/**
    Returns sin of x

*/
double f(double x) {
  double y = 0;
  y = sin(x);
  return y;
}
