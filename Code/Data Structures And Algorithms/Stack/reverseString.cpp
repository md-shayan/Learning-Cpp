// Given a string, reverse it using stack. 
#include <iostream>
#include <string>
#include "Stack.h"

// Iterate over the given string,
// push the letters on to a stack
// set the string to an empty string
// Pop off the top letter to the string until its empty
// Time Complexity: O(N)
// Space Complexity: O(N)
void reverseString(std::string& str) {
	Stack<char> letters;
	for (int i=0; i<str.length(); i++ ) {
		letters.push(str[i]);
	}
	str = "";
	while (!letters.empty()) {
		str += letters.top();
		letters.pop();
	}
}

int main() {
	std::string str1 = "Haiyaaaaaah";
	std::cout << str1 << std::endl;
	reverseString(str1);
	std::cout << str1 << std::endl;
	return 0;
}
