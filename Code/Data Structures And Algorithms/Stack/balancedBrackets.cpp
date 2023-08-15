// Given an expression string exp, write a program to examine whether the pairs and the orders of '{', '}', '(', ')', '[', ']' are correct in the given expression.

#include <iostream>
#include <stack>
#include "Stack.h"

// Iterate over the given expression,
// If the current element is an opening bracket, then push it to the stack
// Else, check if the top of the stack is the opening bracket for the current element
// If it is, then pop off the stack, otherwise return false
// After the iteration is over, return true
// Time Complexity: O(N)
// Space Complexity: O(N)
bool checkBalancedBrackets(std::string expression) {
	Stack<char> openingBrackets;
	for (int i=0; i<expression.length(); i++) {
		if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{')) {
			openingBrackets.push(expression[i]);
		}
		else {
			if ((expression[i] == ')' && openingBrackets.top() == '(') || (expression[i] == ']' && openingBrackets.top() == '[') || (expression[i] == '}' && openingBrackets.top() == '{')) {openingBrackets.pop();}
			else {return 0;}
		}
	}
	return 1;
}

int main() {
	std::string expr = "[()]{}{[()()]()}";
	std::cout << expr << std::endl;
	std::cout << checkBalancedBrackets(expr) << std::endl;

	std::string expr2 = "[(])";
	std::cout << expr2 << std::endl;
	std::cout << checkBalancedBrackets(expr2) << std::endl;
	return 0;
}
