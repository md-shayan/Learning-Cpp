// std::vector[n]
// Returns a reference to the element at n-th position of the vector.

// std::vector.at(n)
// Returns a reference to the element at n-th position of the vector.

// std::vector.data()
// Returns a pointer to the array containting the data of the vector.

// std::vector.front()
// Returns a reference to the first element of the vector.

// std::vector.back()
// Returns a reference to the last element of the vector.

#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	for (int i=1; i<=5; i++) {v.push_back(i);}
	for (auto i=v.begin(); i!=v.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	for (int i=0; i<v.size(); i++) {std::cout << v[i] << " ";}
	std::cout << std::endl;
	for (int i=0; i<v.size(); i++) {std::cout << v.at(i) << " ";}
	std::cout << std::endl;
	int* arr = v.data();
	for (int i=0; i<5; i++) {std::cout << *arr+i << " ";}
	std::cout << std::endl;
	std::cout << v.front() << std::endl;
        std::cout << v.back() << std::endl;
	return 0;
}
