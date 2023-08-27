// ADD_BINARY_INT(A, B, bits):
// C is an array of size bits+1
// carry = 0
// for i=bits-1 downto 0
// 	sum = A[i] + B[i] + carry
// 	if sum == 0
// 		C[i+1] = 0
// 		carry = 0
// 	else if sum == 1
// 		C[i+1] = 0
// 		carry = 0
// 	else if sum == 2
// 		C[i+1] = 0
// 		carry = 1
// 	else if summ == 3
// 		C[i+1] = 1
// 		carry = 1
// 	C[0] = carry
// 	return C

// Time Complexity: O(N)
// Space Complexity: O(N) [For the result]

#include <iostream>
#include <vector>

std::vector<int> add_binary_int(std::vector<int> A, std::vector<int> B, int bits) {
	std::vector<int> C;
    	C.resize(bits + 1);
    	int carry = 0;

    	for (int i = bits - 1; i >= 0; i--) {
        	int sum = A[i] + B[i] + carry;
        	if (sum == 0) {
            	C[i + 1] = 0;
            	carry = 0;
        }
	else if (sum == 1) {
            	C[i + 1] = 1;
            	carry = 0;
        }
	else if (sum == 2) {
            	C[i + 1] = 0;
            	carry = 1;
        }
	else if (sum == 3) {
            	C[i + 1] = 1;
            	carry = 1;
        }
    }

    	C[0] = carry;
    	return C;
}

int main() {
	std::vector<int> A = {1, 0, 0, 0, 1};
	std::cout << "  ";
	for (auto i=A.begin(); i!=A.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	 	
	std::vector<int> B = {1, 1, 1, 0, 1};
	std::cout << "+ ";
	for (auto i=B.begin(); i!=B.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	
	std::vector<int> C = add_binary_int(A, B, 5);
	for (auto i=C.begin(); i!=C.end(); i++) {std::cout << *i << " ";}
	std::cout << std::endl;
	return 0;
}
