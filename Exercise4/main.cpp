/**
 Programming SS 2019 - Problem Set 3
 Exercise 4
 Authors: Elena Pfefferlé, Pascal Schenk
*/
#include <iostream>
#include <cmath>            // to use sin
#include <fstream>
// user defined library
#include "simpson/simpson.hpp"

# define PI 3.14159265358979323846

using namespace std;

// integrands
double f(double x);
double g(double x);

int main(void)
{
  // set output precision to 15 digits
  std::cout.precision(15);
  // redirect COUT to preserve precision
  std::ofstream out("result.txt");
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(out.rdbuf());
  // performs simpson integration for i = 1 to 70
  for (int i = 1; i<=70; i++)
  {
    //writes results in the file
    std::cout << i << "    " <<  simpson(f, 0, PI, i) << endl;
  }
  // reset standard output
  std::cout.rdbuf(coutbuf);
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
/**
    Returns sin of x

*/
double f(double x) {
  double y = 0;
  y = sin(x);
  return y;
}
