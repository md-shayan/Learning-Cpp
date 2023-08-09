//Given a Linked List and a number N, write a function that returns the value at
//the Nth node from the end of the Linked List.
#include <iostream>
#include "LinkedList.h"

//Time Complexity: O(N)
//Space Complexity: O(1)

template<typename T>
T getNthNodeFromEnd(LinkedList<T> LL, int N) {
    int length = 0;
    Node<T>* currentNode = LL.head;
    if (LL.isCircular) {
        length++;
        while (currentNode->next != LL.head) {
            length++;
            currentNode = currentNode->next;
        }
    }

    else {
        while (currentNode != nullptr) {
            length++;
            currentNode = currentNode->next;
        }
    }

    currentNode = LL.head;
    for (int i=0; i<N-length; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

int main() {
    LinkedList<int> LL;
    LL.addAtHead(20);
    LL.addAtHead(4);
    LL.addAtHead(15);
    LL.addAtHead(35);
    LL.print();
    std::cout<<getNthNodeFromEnd(LL, 4)<<std::endl;

    LinkedList<int> LL2(0, 1);
    LL2.addAtHead(20);
    LL2.addAtHead(4);
    LL2.addAtHead(15);
    LL2.addAtHead(35);
    LL2.print();
    std::cout<<getNthNodeFromEnd(LL2, 4)<<std::endl;
    return 0;
}