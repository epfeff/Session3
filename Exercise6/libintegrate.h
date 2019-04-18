/**
 libintegrate.h

 Author: Elena Pfefferlé
 Contact: eapfefferle@gmail.com
*/
#include <assert.h>

// function declaration
template<typename F, typename T>T simpson(F& f, T a, T b, unsigned n);

/**
 Computes the area between intervals 'a' and 'b' of a function 'f' using 'n' bins.
 - a must be different than b.
 - b must be greater than a.
 - n must be greater than 0.
 - f must return one double value.

 Arguments:
 - f is a function that takes a double x and returns a double.
 - a is a double, it represents the lowest point of the interval.
 - b is a double, it represents the highest point of the interval.
 - n is a double, it represents the quantity of bins to analyze
*/
template<typename F, typename T> T simpson(F& f, T a, T b, unsigned n)
{
  // precondition: a != b
  // precondition: b > a
  // precondition: n < 0
  // precondition: f returns one double value
  // postcondidition: returns the area computed
  assert(a != b && "A must be different from B !");
  assert(a < b && "B must be greater than A !");
  assert(n > 0 && "N must be greater than 0 !");
  // declarations
  T area = 0;
  // computes delta x
  T h = (b -a )/n;
    // first and last item of the formula
    area = area + f(a);
    area = area + f(b);
    // calcul area for each bin
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
    return area;
}
