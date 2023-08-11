#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

int precedence(char c) {
    if (c == '^') {return 3;}
    if (c == '*' || c == '/') {return 2;}
    if (c == '+' || c == '-') {return 1;}
    return 0;
}

// Reverse the given expression and swap '(' & ')'
// Iterate over the expression, and convert it to postfix
// Again reverse the new expression and swapping '(' & ')'
// Time Complexity: O(N)
// Space Complexity: O(N)
std::string infixToPrefix(std::string expression) {
    std::stack<char> st;
    reverse(expression.begin(), expression.end());
    for (int i=0; i<expression.length(); i++) {
        if (expression[i] == ')') {
            expression[i] = '(';
        }
        else if (expression[i] == '(') {
            expression[i] = ')';
        }
        else {
            continue;
        }
    }
    std::string result;
    for (int i=0; i<expression.length(); i++) {
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z')) {
            result += expression[i];
        }
        else if (expression[i] == '(') {
            st.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {st.pop();}
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(expression[i])) {
                result += st.top();
                st.pop();
            }
            st.push(expression[i]);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    for (int i=0; i<expression.length(); i++) {
        if (expression[i] == ')') {
            expression[i] = '(';
        }
        else if (expression[i] == '(') {
            expression[i] = ')';
        }
        else {
            continue;
        }
    }
    return result;
}

int main() {
    std::string expr = "A*B+C*D";
    std::cout << expr << std::endl;
    std::cout << infixToPrefix(expr) << std::endl;

    std::string expr2 = "(A+B)*(C+D)";
    std::cout << expr2 << std::endl;
    std::cout << infixToPrefix(expr2) << std::endl;
    return 0;
}