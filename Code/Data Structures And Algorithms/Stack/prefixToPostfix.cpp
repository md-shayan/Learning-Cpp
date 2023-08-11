#include <iostream>
#include <string>
#include <stack>

// Iterate over the expression from the last
// If the current element is NOT an operator, push it to the stack
// Else pop out the stack twice, concatenate them with the operator at the end, and push the new string back to the stack
// After the iteration is over, return the top of the stack
// Time Complexity: O(N)
// Space Complexity: O(N)
std::string prefixToPostfix(std::string expression) {
	std::stack<std::string> st;
	char c;
	std::string newString;
	for (int i=expression.length()-1; i>=0; i--) {
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
			newString = opr1 + opr2 + c;
			st.push(newString);	
		}
	}
	return st.top();
}

int main() {
	std::string expr = "*+AB-CD";
	std::cout << expr << std::endl;
	std::cout << prefixToPostfix(expr) << std::endl;

	std::string expr2 = "*-A/BC-/AKL";
	std::cout << expr2 << std::endl;
	std::cout << prefixToPostfix(expr2) << std::endl;
	return 0;
}
