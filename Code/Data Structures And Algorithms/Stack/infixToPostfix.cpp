#include <iostream>
#include "Stack.h"
#include <string>

int precedence(char c) {
	if (c == '^') {return 3;}
	else if (c == '*' || c == '/') {return 2;}
	else if (c == '+' || c == '-') {return 1;}
	else {return -1;}
}

// Iterate over the given expression,
// If the current character is a letter then add it to the result string
// Else if it is '(' then push it onto the stack
// Else if it is ')' then add it to the result string and pop it off the stack until the top element is not '(', Pop off the last '(' too
// Else, while the precedence of the top is greater than the current character, add it to the result string and pop off the top, and push the current character to the stack
// After the iteration is over, copy back all the remaining characters from the stack back to the result string

// Time Complexity: O(N)
// Space Complexity: O(N)
std::string infixToPostfix(std::string expression) {
	Stack<char> operands;
	std::string result = "";
	for (int i=0; i<expression.length(); i++) {
		if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z')) {
			result += expression[i];
		}
		else if (expression[i] == '(') {
			operands.push(expression[i]);
		}
		else if (expression[i] == ')') {
			while (!operands.empty() && operands.top() != '(') {
				result += operands.top();
				operands.pop();
			}
			if (!operands.empty()) {
				operands.pop();
			}
		}
		else {
			while (!operands.empty() && precedence(operands.top()) >= precedence(expression[i])) {
				result += operands.top();
				operands.pop();
			}
			operands.push(expression[i]);
		}
	}
	while (!operands.empty()) {
		result += operands.top();
		operands.pop();
	}
	return result;
}

int main() {
	std::string expr{"a+b*c+d"};
	std::string expr2{"a+b*(c^d-e)^(f+g*h)-i"};
	std::cout << expr << std::endl;
	std::cout << infixToPostfix(expr) << std::endl;
	std::cout << expr2 << std::endl;
	std::cout << infixToPostfix(expr2) << std::endl;
	return 0;
}
