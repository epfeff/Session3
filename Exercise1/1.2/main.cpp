/**
 Programming SS 2019 - Problem Set 3
 Exercise 1.2
 Authors: Elena Pfefferlé, Pascal Schenk
*/
#include <iostream>
#include <vector>         // to use vectors
#include <numeric>        // to use  accumulate
#include <algorithm>      // to use for_each

using namespace std;


// print an array from end to beginning
void printReverse(vector<double> array, int size);

int main(void)
{
    // to store sequence size
    int n;
    // to store user inputs
    int p;
    // to compute the sum of the sequence
    double sum = 0;
    // dynamic array to store the sequence
    vector<double> sequence;
    // Asks user for the quantity of values (sequence size)
    std::cout << "! Non numerical values will crash the program !" << endl;
    std::cout << "Number of values: ";
    std::cin >>n;
    // Sets array size to n
    sequence.resize(n);
    // Asks user to input the values to store into the sequence
    for (int i = 0; i<n; i++) {
      std::cout << "Value " << i << ": ";
      std::cin >> p;
      sequence[i] = p;
    }
    // finds sum of the sequence
    sum = std::accumulate(sequence.begin(), sequence.end(), 0);
    // divides sequence items by the sum
    std::for_each(sequence.begin(), sequence.end(), [sum](double& n){n=n/sum;});
    // output reversed nomalized sequence
    printReverse(sequence, n);
    return(0);
}

// Output a reversed normalized sequence
void printReverse(vector<double> array, int size) {
  std::cout << "Reverse normalized sequence: [";
  for (int i = size-1; i>=0; i--) {
    std::cout << array[i];
    if (i != 0) {
      std::cout << ", " ;
    }
  }
  std::cout << "]" << endl;
}
