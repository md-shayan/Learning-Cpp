//Given a circular linked list, count the number of nodes in it.
#include <iostream>
#include "LinkedList.h"

template <typename T>
int countNodes(SinglyCircularLinkedList<T> SCLL) {
    int count = 0;
    if (SCLL.head != nullptr) {count++;}
    SinglePointingNode<T>* currentNode = SCLL.head->next;
    while (currentNode != SCLL.head) {
        count++;
        currentNode = currentNode->next;
    }
    return count;
}

template <typename T>
int countNodes(DoublyCircularLinkedList<T> DCLL) {
    int count = 0;
    if (DCLL.head != nullptr) {count++;}
    DoublePointingNode<T>* currentNode = DCLL.head->next;
    while (currentNode != DCLL.head) {
        count++;
        currentNode = currentNode->next;
    }
    return count;
}

int main() {
    SinglyCircularLinkedList<int> SCLL;
    SCLL.addAtHead(4);
    SCLL.addAtHead(3);
    SCLL.addAtHead(2);
    SCLL.addAtHead(1);
    SCLL.print();
    std::cout<<countNodes(SCLL)<<std::endl;

    DoublyCircularLinkedList<int> DCLL;
    DCLL.addAtHead(4);
    DCLL.addAtHead(3);
    DCLL.addAtHead(2);
    DCLL.addAtHead(1);
    DCLL.print();
    std::cout<<countNodes(DCLL)<<std::endl;
    return 0;
}