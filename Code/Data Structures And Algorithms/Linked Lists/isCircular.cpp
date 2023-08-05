//Given a singly linked list, find if the linked list is circular or not.
#include <iostream>
#include "LinkedList.h"

//TIme Complexity: O(N)
//Space Complexity: O(1)

template <typename T>
bool isCircular(SinglyLinkedList<T> SLL) {
    if (SLL.head->next == SLL.head) {
        return 1;
    }
    SinglePointingNode<T>* lastNode = SLL.head->next;
    while (lastNode != nullptr && lastNode != SLL.head) {
        lastNode = lastNode->next;
    }
    return (lastNode == SLL.head);
}

template <typename T>
bool isCircular(SinglyCircularLinkedList<T> SCLL) {
    if (SCLL.head->next == SCLL.head) {
        return 1;
    }
    SinglePointingNode<T>* lastNode = SCLL.head->next;
    while (lastNode != nullptr && lastNode != SCLL.head) {
        lastNode = lastNode->next;
    }
    return (lastNode == SCLL.head);
}

template <typename T>
bool isCircular(DoublyLinkedList<T> DLL) {
    if (DLL.head->prev == nullptr) {return 0;}
    return 1;
}

template <typename T>
bool isCircular(DoublyCircularLinkedList<T> DCLL) {
    if (DCLL.head->prev == nullptr) {return 0;}
    return 1;
}

int main() {
    SinglyLinkedList<int> SLL;
    SLL.addAtHead(4);
    SLL.addAtHead(3);
    SLL.addAtHead(2);
    SLL.addAtHead(1);
    SLL.print();
    std::cout<<isCircular(SLL)<<std::endl;

    DoublyLinkedList<int> DLL;
    DLL.addAtHead(4);
    DLL.addAtHead(3);
    DLL.addAtHead(2);
    DLL.addAtHead(1);
    DLL.print();
    std::cout<<isCircular(DLL)<<std::endl;

    SinglyCircularLinkedList<int> SCLL;
    SCLL.addAtHead(4);
    SCLL.addAtHead(3);
    SCLL.addAtHead(2);
    SCLL.addAtHead(1);
    SCLL.print();
    std::cout<<isCircular(SCLL)<<std::endl;
    
    DoublyCircularLinkedList<int> DCLL;
    DCLL.addAtHead(4);
    DCLL.addAtHead(3);
    DCLL.addAtHead(2);
    DCLL.addAtHead(1);
    DCLL.print();
    std::cout<<isCircular(DCLL)<<std::endl;
    return 0;
}