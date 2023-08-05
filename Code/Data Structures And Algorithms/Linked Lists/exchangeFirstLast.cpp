//Given Circular linked list exchange the first and the last node. The task should be done with only one extra node.
#include <iostream>
#include "LinkedList.h"

//Time Compleixty: O(N)
//Space Compleixty: O(1)
template <typename T>
void exchangeFirstLastNodes(SinglyCircularLinkedList<T> SCLL) {
    SinglePointingNode<T>* lastNode = SCLL.head;
    while (lastNode->next != SCLL.head) {
        lastNode = lastNode->next;
    }
    T temp = SCLL.head->data;
    SCLL.head->data = lastNode->data;
    lastNode->data = temp;
}

//Time Compleixty: O(1)
//Space Compleixty: O(1)
template <typename T>
void exchangeFirstLastNodes(DoublyCircularLinkedList<T> DCLL) {
    DoublePointingNode<T>* lastNode = DCLL.head->prev;
    T temp = DCLL.head->data;
    DCLL.head->data = lastNode->data;
    lastNode->data = temp;
}

int main() {
    SinglyCircularLinkedList<int> SCLL;
    SCLL.addAtHead(4);
    SCLL.addAtHead(3);
    SCLL.addAtHead(2);
    SCLL.addAtHead(1);
    SCLL.print();
    exchangeFirstLastNodes(SCLL);
    SCLL.print();

    DoublyCircularLinkedList<int> DCLL;
    DCLL.addAtHead(4);
    DCLL.addAtHead(3);
    DCLL.addAtHead(2);
    DCLL.addAtHead(1);
    DCLL.print();
    exchangeFirstLastNodes(DCLL);
    DCLL.print();
    return 0;
}