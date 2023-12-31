//Write a program to reverse a stack using recursion, without using any loop.

#include <iostream>
#include "Stack.h"

void insertAtBottom(Stack<int>& st, int elem) {
	if (st.empty()) {
		st.push(elem);
		return;
	}
	int topElem = st.top();
	st.pop();
	insertAtBottom(st, elem);
	st.push(topElem);
}

// Store the top element and pop out the stack recursively and insert the top element at the bottom of the stack recursively
// Time Complexity: O(N^2)
// Space Complexity: O(N)
void reverse(Stack<int>& st) {
	if (st.empty()) {return;}
	int topElem = st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st, topElem);
}

void printStack(Stack<int> st) {
	while (!st.empty()) {
		std::cout << st.top() << " -> ";
		st.pop();
	}
	std::cout << std::endl;
}

int main() {
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.print();
	reverse(st);
	st.print();
	return 0;
}
