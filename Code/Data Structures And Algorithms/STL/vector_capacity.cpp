// std::vector.size()
// Returns the number of elements present in the vector. 

// std::vector.capacity()
// Returns the size of storage space currently allocated to vector.

// std::vector.max_size()
// Returns the max number of elements the vector can hold (for 64-bit system it is 2^61 - 1).

// std::vector.reserve(n)
// Reserves space for n number of elements.

// std::vector.resize(n)
// Resizes vector to n number of elements by deleting all other elements.

// std::vector.empty()
// Returns whether the vector is empty or not.

#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << v.max_size() << std::endl;
	v.empty() ? std::cout << "True" : std::cout << "False";
	std::cout << std::endl;
	
	v.reserve(5);
	for (int i=1; i<=10; i++) {v.push_back(i);}

	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;

	v.resize(5);

	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;

	std::cout << v.size() << std::endl;
        std::cout << v.capacity() << std::endl;
        std::cout << v.max_size() << std::endl;
	std::cout << v.empty() << std::endl;
	v.empty() ? std::cout << "True" : std::cout << "False";
        std::cout << std::endl;

	return 0;
}
