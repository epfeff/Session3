#include <iostream>
#include "iterator.hpp"
#include "array.hpp"

int main()
{
	// Print numbers in normal order
	const size_t N = 5;
	int nums[] = {1,2,3,4,5};

	for( size_t i = 0 ; i < N ; ++i )
		std::cout << nums[i];
	std::cout << std::endl;

	Array<int> array( N );

	// Load numbers into array
	Array<int>::iterator iter = array.begin();

	for( size_t i = 0 ; i < N ; ++i )
		*iter++ = nums[ i ]; // InputIterator use

	// print the copied array the normal way
	//for (iter = array.begin(); iter != array.end(); ++iter)
	//	std::cout << *iter;
	//std::cout << std::endl;

	// uncomment these lines if you have bidirectional support
	// Print numbers in reverse order
	//iter = array.end();
	//do {
	//   std::cout << *(--iter);
	//} while( iter != array.begin() );
	//std::cout << std::endl;

	return 0;
}
