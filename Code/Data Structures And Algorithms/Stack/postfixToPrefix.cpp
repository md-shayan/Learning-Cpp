#include <iostream>
#include <string>
#include "Stack.h"

// Iterate over the given expression,
// If the current element is NOT an operator, then push it to the stack
// Else, pop out the stack twice and concatenate the operator with the two strings and push the new string back to the stack
// Once the iteration is over, return the top of the stack
// Time Complexity: O(N)
// Space Complexity: O(N)
std::string postfixToPrefix(std::string expression) {
	Stack<std::string> st;
	char c;
	std::string newString;
	for (int i=0; i<expression.length(); i++) {
		c = expression[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			newString = c;
			st.push(newString);
		}
		else {
			std::string opr1 = st.top();
			st.pop();
			std::string opr2 = st.top();
			st.pop();
			newString = c + opr2 + opr1;
			st.push(newString);
		}
	}
	return st.top();
}

int main() {
	std::string expr = "AB+CD-*";
	std::cout << expr << std::endl;
	std::cout << postfixToPrefix(expr) << std::endl;

	std::string expr2 = "ABC/-AK/L-*";
	std::cout << expr2 << std::endl;
	std::cout << postfixToPrefix(expr2) << std::endl;
	return 0;
}
