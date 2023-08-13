// Given string str, we need to print the reverse of individual words.
#include <iostream>
#include <string>
#include <stack>

// Iterate over the given string from the end
// Whenever a non-space character is encountered, store it into a word variable
// Otherwise, push the word to the stack of words
// After the iteration is over, push the last word to the stack
// Add the words to the sentece by popping out the stack until its empty
// Time Compelxity: O(N)
// Space Complexity: O(N)
void reverseWords(std::string& sentence) {
	std::stack<std::string> words;
	std::string word = "";
	for (int i=sentence.length()-1; i>=0; i--) {
		if (sentence[i] == ' ') {
			words.push(word);
			word = "";
		}
		else {
			word += sentence[i];
		}
	}
	words.push(word);
	sentence = "";
	while (!words.empty()) {
		sentence += words.top() + " ";
		words.pop();
	}
}

int main() {
	std::string sentence = "Hello World";
	std::cout << sentence << std::endl;
	reverseWords(sentence);
	std::cout << sentence << std::endl;

	std::string sentence2 = "Geeks for Geeks";
	std::cout << sentence2 << std::endl;
	reverseWords(sentence2);
	std::cout << sentence2 << std::endl;
	return 0;
}
