// std::vector.assign(times, value)
// Fills the vector with given value with 'times' number of time.

// std::vector.push_back(value)
// Appends value at the end of the vector.

// std::vector.pop_back(value)
// Removes the last element of the vector.

// std::vector.insert(address, value)
// Puts given value at the given address.

// std::vector.erase(address)
// Removes the element at the given address.

// std::vector.emplace(address, value)
// Puts the given value at the given address.

// std::vector.emplace_back(value)
// Puts the given value at the end of the vector.

// std::vector.clear()
// Removes all the elements from the vector.

// std::vector.swap(std::vector)
// Replaces all the elements of the given vector with the vector.

#include <iostream>
#include <vector>
#include <numeric>

int main() {
	std::vector<int> v;
	
	v.assign(10, 10);
	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	
	v.push_back(100);
	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	
	v.pop_back();
	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	
	v.insert(v.begin(), 0);
	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	
	v.erase(v.begin());
	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	
	v.emplace(v.begin(), 0);
	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
        std::cout << std::endl;

	v.emplace_back(100);
	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
        std::cout << std::endl;
	
	v.clear();
	v.empty() ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;

	std::vector<int> x;
	v.resize(5);
	std::iota(v.begin(), v.end(), 1);

	x.resize(5);
	std::iota(x.begin(), x.end(), 6);

	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
        std::cout << std::endl;

	for (auto i=x.begin(); i!=x.end(); i++) {std::cout << *i << " ";}
        std::cout << std::endl;

	v.swap(x);

	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
        std::cout << std::endl;

	for (auto i=x.begin(); i!=x.end(); i++) {std::cout << *i << " ";}
        std::cout << std::endl;
	return 0;
}
