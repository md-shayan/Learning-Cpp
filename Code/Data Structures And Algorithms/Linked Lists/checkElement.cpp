//Given a linked list and a key 'X' in, the task is to check if X is present in the linked list or not. 
#include <iostream>
#include "LinkedList.h"

//Iterative
//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
bool isPresent(DoublyLinkedList<T> DLL, T X) {
    DoublePointingNode<T>* currentNode = DLL.head;
    while (currentNode->X != X) {
        currentNode = currentNode->next;
        if (currentNode == nullptr) {return 0;}
    }
    return 1;
}

//Recursive
//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
bool isPresent(DoublePointingNode<T>* currentNode, T X) {
    if (currentNode != nullptr) {
        if (currentNode->data == X) {return 1;}
        return isPresent(currentNode->next, X);
    }
    else {
        return 0;
    }
}

int main() {
    DoublyLinkedList<int> DLL;
    DLL.addAtHead(4);
    DLL.addAtHead(3);
    DLL.addAtHead(2);
    DLL.addAtHead(1);
    DLL.print();
    std::cout<<isPresent(DLL.head, 1)<<std::endl;
    return 0;
}