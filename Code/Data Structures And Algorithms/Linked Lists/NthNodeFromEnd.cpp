//Given a Linked List and a number N, write a function that returns the value at
//the Nth node from the end of the Linked List.
#include <iostream>
#include "LinkedList.h"

//Time Complexity: O(N)
//Space Complexity: O(1)

template<typename T>
T getNthNodeFromEnd(SinglyLinkedList<T> SLL, int N) {
    int length = 0;
    SinglePointingNode<T>* currentNode = SLL.head;
    while (currentNode != nullptr) {
        length++;
        currentNode = currentNode->next;
    }
    currentNode = SLL.head;
    for (int i=0; i<N-length; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<typename T>
T getNthNodeFromEnd(SinglyCircularLinkedList<T> SCLL, int N) {
    int length = 0;
    SinglePointingNode<T>* currentNode = SCLL.head;
    while (currentNode != nullptr) {
        length++;
        currentNode = currentNode->next;
    }
    currentNode = SCLL.head;
    for (int i=0; i<N-length; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<typename T>
T getNthNodeFromEnd(DoublyLinkedList<T> DLL, int N) {
    int length = 0;
    DoublePointingNode<T>* currentNode = DLL.head;
    while (currentNode != nullptr) {
        length++;
        currentNode = currentNode->next;
    }
    currentNode = DLL.head;
    for (int i=0; i<N-length; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<typename T>
T getNthNodeFromEnd(DoublyCircularLinkedList<T> DCLL, int N) {
    int length = 0;
    DoublePointingNode<T>* currentNode = DCLL.head;
    while (currentNode != nullptr) {
        length++;
        currentNode = currentNode->next;
    }
    currentNode = DCLL.head;
    for (int i=0; i<N-length; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

int main() {
    DoublyLinkedList<int> SLL;
    SLL.addAtHead(20);
    SLL.addAtHead(4);
    SLL.addAtHead(15);
    SLL.addAtHead(35);
    SLL.print();
    std::cout<<getNthNodeFromEnd(SLL, 4);
    return 0;
}