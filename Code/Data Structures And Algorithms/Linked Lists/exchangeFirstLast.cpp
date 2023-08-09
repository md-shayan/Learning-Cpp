//Given linked list exchange the first and the last node. The task should be done with only one extra node.
#include <iostream>
#include "LinkedList.h"

//Time Compleixty: O(N)
//Space Compleixty: O(1)
template <typename T>
void exchangeFirstLastNodes(LinkedList<T> LL) {
    if (LL.isCircular) {
        Node<T>* lastNode = LL.head;
        while (lastNode->next != LL.head) {
            lastNode = lastNode->next;
        }
        T temp = LL.head->data;
        LL.head->data = lastNode->data;
        lastNode->data = temp;
    }
    else {
        Node<T>* lastNode = LL.head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        T temp = LL.head->data;
        LL.head->data = lastNode->data;
        lastNode->data = temp;
    }
}

int main() {
    LinkedList<int> LL;
    LL.addAtHead(4);
    LL.addAtHead(3);
    LL.addAtHead(2);
    LL.addAtHead(1);
    LL.print();
    exchangeFirstLastNodes(LL);
    LL.print();

    LinkedList<int> LL2(0, 1);
    LL2.addAtHead(4);
    LL2.addAtHead(3);
    LL2.addAtHead(2);
    LL2.addAtHead(1);
    LL2.print();
    exchangeFirstLastNodes(LL2);
    LL2.print();
    return 0;
}