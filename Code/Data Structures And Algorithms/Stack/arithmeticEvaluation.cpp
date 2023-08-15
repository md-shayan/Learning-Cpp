#include <iostream>
#include <string>
#include "Stack.h"

int precedence(char c) {
        if (c == '^') {return 3;}
        else if (c == '*' || c == '/') {return 2;}
        else if (c == '+' || c == '-') {return 1;}
        else {return -1;}
}

std::string infixToPostfix(std::string expression) {
	Stack<char> operands;
        std::string result = "";
        for (int i=0; i<expression.length(); i++) {
                if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= '0' && expression[i] <= '9')) {
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

int toInt(char c) {
	if (c == '0') return 0;
	if (c == '1') return 1;
	if (c == '2') return 2;
	if (c == '3') return 3;
	if (c == '4') return 4;
	if (c == '5') return 5;
	if (c == '6') return 6;
	if (c == '7') return 7;
	if (c == '8') return 8;
	if (c == '9') return 9;
	return -1;
}

// Iterate over the given postfix expression,
// If the current element is a char in '0' to '9', convert it to an int and push it to the stack
// Else if the current element is an operand, pop off the stack twice and then push back the numbers with the operation performed
// Once the iteration is over, return the top of the stack
// Time Complexity: O(N)
// Space Complexity: O(N)
int evaluation(std::string expr) {
	Stack<int> st;
	int current;
	for (int i=0; i<expr.length(); i++) {
		if (expr[i] >= '0' && expr[i] <= '9') {
			current = toInt(expr[i]);
			st.push(current);	
		}
		else {
			int opr1 = st.top();
			st.pop();
			int opr2 = st.top();
			st.pop();
			if (expr[i] == '+') {current = opr2 + opr1;}
			else if (expr[i] == '-') {current = opr2 - opr1;}
			else if (expr[i] == '*') {current = opr2 * opr1;}
			else if (expr[i] == '/') {current = opr2 / opr1;}
			st.push(current);
		}
	}
	return st.top();
}

int main() {
	std::string expr = "(2+4)*(4+6)";
	std::cout << expr << std::endl;
	std::string postfix_expr = infixToPostfix(expr);
	std::cout << postfix_expr << std::endl;
	std::cout << evaluation(postfix_expr) << std::endl;

	std::string expr2 = "2+(3*1)-9";
	std::cout << expr2 << std::endl;
	std::string postfix_expr2 = infixToPostfix(expr2);
	std::cout << postfix_expr2 << std::endl;
	std::cout << evaluation(postfix_expr2) << std::endl;
	return 0;
}
