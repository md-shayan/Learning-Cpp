// std::vector.push_back(x)
// pushes x to the end of vector.

// std::vector.begin(), std::vector.end()
// Returns an iterator pointing to the first and last element of the vector respectively.

// std::vector.cbegin(), std::vector.cend()
// Returns a constant iterator pointing to the first and last element of the vector respectively.

// std::vector.rbegin(), std::vector.rend()
// Returns an iterator pointing to the last and first element of the vector respectively.

// std::vector.crbegin(), std::vector.crend()
// Returns a constant iterator pointing to the last and first element of the vector respectively.

#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	for (int i=1; i<=5; i++) {vec.push_back(i);}
	
	for (auto i=vec.begin(); i!=vec.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	
	for (auto i=vec.cbegin(); i!=vec.cend(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;

	for (auto i=vec.rbegin(); i!=vec.rend(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;

	for (auto i=vec.crbegin(); i!=vec.crend(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;

	return 0;
}
