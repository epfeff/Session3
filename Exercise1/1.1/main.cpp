/**
 Programming SS 2019 - Problem Set 3
 Exercise 1.1
 Authors: Elena Pfefferlé, Pascal Schenk
*/
#include <iostream>

using namespace std;
// declarations

// print an array from end to beginning
void printReverse(double array[], int size);

int main(void)
{
    // to store sequence size
    int n;
    // to store user input
    double p;
    // to compute the sum of the sequence
    double sum = 0;
    // Asks user for the quantity of values (sequence size)
    std::cout << "! Non numerical values will crash the program !" << endl;
    std::cout << "Number of values: ";
    std::cin >>n;
    double sequence[n];
    // Asks user to input the values to store in the sequence
    for (int i = 0; i<n; i++) {
      std::cout << "Value " << i << ": ";
      std::cin >> p;
      sequence[i] = p;
    }
    // finds sum of the sequence
    for (int i = 0; i<n; i++) {
      sum = sum + sequence[i];
    }
    // divides sequence items by the sum
    for (int i = 0; i<n; i++) {
      sequence[i] = sequence[i]/sum;
    }
    // output reversed nomalized sequence
    printReverse(sequence, n);
    return(0);
}

// Output a reversed normalized sequence
void printReverse(double array[], int size) {
  std::cout << "Reverse normalized sequence: [";
  for (int i = size-1; i>=0; i--) {
    std::cout << array[i];
    if (i != 0) {
      std::cout << ", " ;
    }
  }
  std::cout << "]" << endl;
}
