#include <iostream>
#include <stack>

int main() {
    std::stack<char> s;
    char name[]{"emaN ruoY"};
    int size = sizeof(name) / sizeof(char);
    for (int i = 0; i < size; i++) {
        s.push(name[i]);
    }
    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
    std::cout << std::endl;
    return 0;
}