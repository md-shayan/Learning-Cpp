//Given a singly linked list, we have to convert it into circular linked list.
#include <iostream>
#include "LinkedList.h"

//Time Compleixty: O(N)
//Space Compleixty: O(1)

template <typename T>
SinglePointingNode<T>* toCircular(SinglyLinkedList<T> SLL) {
    if (SLL.head == nullptr) {
        return SLL.head;
    }
    if (SLL.head->next == nullptr) {
        SLL.head->next = SLL.head;
        return SLL.head;
    }
    SinglePointingNode<T>* lastNode = SLL.head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = SLL.head;
    return SLL.head;
}

template <typename T>
DoublePointingNode<T>* toCircular(DoublyLinkedList<T> DLL) {
    if (DLL.head == nullptr) {
        return DLL.head;
    }
    if (DLL.head->next == nullptr) {
        DLL.head->next = DLL.head;
        return DLL.head;
    }
    DoublePointingNode<T>* lastNode = DLL.head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = DLL.head;
    DLL.head->prev = DLL.head;
    return DLL.head;
}

int main() {
    SinglyLinkedList<int> SLL;
    SLL.addAtHead(4);
    SLL.addAtHead(3);
    SLL.addAtHead(2);
    SLL.addAtHead(1);
    SLL.print();
    SinglyCircularLinkedList<int> SCLL;
    SCLL.head = toCircular(SLL);
    SCLL.print();

    DoublyLinkedList<int> DLL;
    DLL.addAtHead(4);
    DLL.addAtHead(3);
    DLL.addAtHead(2);
    DLL.addAtHead(1);
    DLL.print();
    DoublyCircularLinkedList<int> DCLL;
    DCLL.head = toCircular(DLL);
    DCLL.print();
    return 0;
}