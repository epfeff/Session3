#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <iterator>
=======
#include <numeric>
#include <algorithm>
>>>>>>> 6aaa3c7a6f4034a0135cff6873a199ab704c980d

using namespace std;
// declarations

// print an array from end to beginning
<<<<<<< HEAD
void printReverse(vector<double>, int size);
=======
void printReverse(vector<double> array, int size);
>>>>>>> 6aaa3c7a6f4034a0135cff6873a199ab704c980d

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
<<<<<<< HEAD
=======
    // Sets array size to n
>>>>>>> 6aaa3c7a6f4034a0135cff6873a199ab704c980d
    sequence.resize(n);
    // Asks user to input the values stored in the sequence
    for (int i = 0; i<n; i++) {
      std::cout << "Value " << i << ": ";
      std::cin >> p;
      sequence[i] = p;
    }
    // finds sum of the sequence
<<<<<<< HEAD
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
=======
    sum = std::accumulate(sequence.begin(), sequence.end(), 0);
    // divides sequence items by the sum
    std::for_each(sequence.begin(), sequence.end(), [sum](double& n){n=n/sum;});
    // output reversed nomalized sequence
    printReverse(sequence, n);
>>>>>>> 6aaa3c7a6f4034a0135cff6873a199ab704c980d
}

// Output a reversed normalized sequence
void printReverse(vector<double> array, int size) {
  std::cout << "Reverse normalized sequence: [";
<<<<<<< HEAD


=======
  for (int i = size-1; i>=0; i--) {
    std::cout << array[i];
    if (i != 0) {
      std::cout << ", " ;
    }
  }
>>>>>>> 6aaa3c7a6f4034a0135cff6873a199ab704c980d
  std::cout << "]" << endl;
}
