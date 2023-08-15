#include <iostream>
#include <string>
#include "Stack.h"

// Iterate over the expression from the end
// if the current element is NOT an operator, push it to the stack
// Else pop out the stack twice and concatenate the operand with the two tops and push the new string back to the stack
// Once the iteration is over, return the top of the stack.
// Time Complexity: O(N)
// Space Complexity: O(N)
std::string prefixToInfix(std::string expression) {
	Stack<std::string> result;
	char c;
	std::string newString;
	for (int i=expression.length()-1; i>=0; i--) {
		c = expression[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) {
			newString = c;
			result.push(newString);
		}
		else {
			std::string opr1 = result.top();
			result.pop();
			std::string opr2 = result.top();
			result.pop();
			newString = "(" + opr1 + expression[i] + opr2 + ")";
			result.push(newString);
		}
	}
	return result.top();
}

int main() {
	std::string expr = "*+AB-CD";
	std::cout << expr << std::endl;
	std::cout << prefixToInfix(expr) << std::endl;

	std::string expr2 = "*-A/BC-/AKL";
	std::cout << expr2 << std::endl;
	std::cout << prefixToInfix(expr2) << std::endl;
	return 0;
}
