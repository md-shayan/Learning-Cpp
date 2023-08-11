#include <iostream>
#include <string>
#include <stack>

// Iterate over the given expression,
// If the current element is NOT an operator, push it to the stack
// Else, pop out the stack twice and concatenate the two popped out strings with the operator in the middle and push the new string to the stack
// After the iteration is over, return the top of the stack
// Time Complexity: O(N)
// Space Complexity: O(N)
std::string postfixToInfix(std::string expression) {
	std::stack<std::string> st;
	char c;
	std::string newString;
	for (int i=0; i<expression.length(); i++ ) {
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
			newString = "(" + opr2 + c + opr1 + ")";
			st.push(newString);
		}
	}
	return st.top();
}

int main() {
	std::string expr = "ABC++";
	std::cout << expr << std::endl;
	std::cout << postfixToInfix(expr) << std::endl;

	std::string expr2 = "AB*C+";
	std::cout << expr2 << std::endl;
	std::cout << postfixToInfix(expr2) << std::endl;
	return 0;
}
