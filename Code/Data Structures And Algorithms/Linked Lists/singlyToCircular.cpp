//Given a singly linked list, we have to convert it into circular linked list.
#include <iostream>
#include "LinkedList.h"

//Time Compleixty: O(N)
//Space Compleixty: O(1)

template <typename T>
Node<T>* toCircular(LinkedList<T> LL) {
    if (LL.head == nullptr) {
        return LL.head;
    }
    if (LL.head->next == nullptr) {
        LL.head->next = LL.head;
        return LL.head;
    }
    Node<T>* lastNode = LL.head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = LL.head;
    return LL.head;
}

int main() {
    LinkedList<int> LL;
    LL.addAtHead(4);
    LL.addAtHead(3);
    LL.addAtHead(2);
    LL.addAtHead(1);
    LL.print();
    LinkedList<int> LL2(0, 1);
    LL2.head = toCircular(LL);
    LL2.print();

    LinkedList<int> DLL(1);
    DLL.addAtHead(4);
    DLL.addAtHead(3);
    DLL.addAtHead(2);
    DLL.addAtHead(1);
    DLL.print();
    LinkedList<int> DLL2(1, 1);
    DLL2.head = toCircular(DLL);
    DLL2.print();
    return 0;
}