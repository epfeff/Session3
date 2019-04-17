#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
// declarations

// print an array from end to beginning
void printReverse(vector<double>, int size);

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
    std::cout << "Number of values: ";
    std::cin >>n;
    sequence.resize(n);
    // Asks user to input the values stored in the sequence
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
    std::cin >>n;
}

// Output a reversed normalized sequence
void printReverse(vector<double> array, int size) {
  std::cout << "Reverse normalized sequence: [";


  std::cout << "]" << endl;
}
