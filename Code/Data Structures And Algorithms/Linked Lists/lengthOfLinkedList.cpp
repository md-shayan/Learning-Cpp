//a function to count the number of nodes in a given singly linked list.
#include <iostream>
#include "LinkedList.h"

//Iterative
//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
int lengthOfLinkedList(SinglyLinkedList<T> SLL) {
    int size = 0;
    SinglePointingNode<T>* currentNode = SLL.head;
    while (currentNode != nullptr) {
        size++;
        currentNode = currentNode->next;
    }
    return size;
}

//Iterative
//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
int lengthOfLinkedList(SinglePointingNode<T>* currentNode, int size=0) {
    if (currentNode != nullptr) {
        size++;
        return lengthOfLinkedList(currentNode->next, size);
    }
    return size;
}

int main() {
    SinglyLinkedList<int> SLL;
    SLL.addAtHead(4);
    SLL.addAtHead(3);
    SLL.addAtHead(2);
    SLL.addAtHead(1);
    SLL.print();
    std::cout<<lengthOfLinkedList(SLL.head);
    return 0;
}