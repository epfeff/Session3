/**
 Programming SS 2019 - Problem Set 3
 Exercise 4
 Author: Elena Pfefferlé
 Contact: eapfefferle@gmail.com
*/
#include <iostream>
#include <cmath>
#include <fstream>
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
  // initiate a file output
  std::ofstream ofs ("result.txt", std::ofstream::out);
  // performs simpson integration for i = 1 to 70
  for (int i = 1; i<=70; i++)
  {
    //writes results in the file
    ofs << i << "    " << simpson(f, 0, PI, i) << endl;
  }
  //closes the file
  ofs.close();
  // creates a files containing plot settings
  std::ofstream stg ("plot_settings", std::ofstream::out);
  stg << "set terminal png; set output 'result.png'; plot 'result.txt' with lines";
  stg.close();
  // check if windows or linux to plot the output and remove plot settings file
  #ifdef WIN32
      system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" plot_settings");
      system("del plot_settings");
  #else
      system("gnuplot plot_settings");
      system("rm plot_settings");
  #endif
  int n = 0;

}
// integrand 1
double f(double x) {
  double y = 0;
  y = sin(x);
  return y;
}
