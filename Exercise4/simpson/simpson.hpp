/**
 simpson.hpp

 Author: Elena Pfefferlé
 Contact: eapfefferle@gmail.com
*/

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

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

  Returns the computed area.
*/
double simpson(double (*f)(double), double a, double b, double n);
// precondition: a != b
// precondition: b > a
// precondition: n < 0
// precondition: f returns one double value
// postcondidition: returns the area computed

#endif
