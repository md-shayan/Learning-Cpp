//Given a linked list and a key 'X' in, the task is to check if X is present in the linked list or not. 
#include <iostream>
#include "LinkedList.h"

//Iterative
//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
bool isPresent(LinkedList<T> ll, T data) {
    if (ll.getNode(data) == nullptr) {return 0;}
    return 1;
}

//Recursive (Only works for non-circular Linked Lists)
//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
bool isPresent(Node<T>* currentNode, T data) {
    if (currentNode != nullptr) {
        if (currentNode->data == data) {return 1;}
        return isPresent(currentNode->next, data);
    }
    else {
        return 0;
    }
}

int main() {
    LinkedList<int> ll(1, 0);
    ll.addAtHead(4);
    ll.addAtHead(3);
    ll.addAtHead(2);
    ll.addAtHead(1);
    ll.print();
    std::cout<<isPresent(ll.head, 5)<<std::endl;
    return 0;
}
