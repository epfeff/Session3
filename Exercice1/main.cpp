#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int p;
    std::cout << "Number of values: ";
    std::cin >>n;
    int foo[n];
    for (int i = 0; i<n; i++) {
      std::cin >> p;
    }

    //for (auto x = std::end(foo); x != std::begin(foo); )
    //{
    //    std::cout <<*--x<< ' ';
    //}

    cout << std::end(foo) << endl;

    //to wait till the end
    std::cin>> n;
    return(0);
}
