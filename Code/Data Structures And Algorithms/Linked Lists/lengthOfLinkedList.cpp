//a function to count the number of nodes in a given singly linked list.
#include <iostream>
#include "LinkedList.h"

//Iterative
//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
int lengthOfLinkedList(LinkedList<T> LL) {
    if (LL.isCircular) {
        int size = 0;
        Node<T>* currentNode = LL.head;
        while (currentNode->next != LL.head) {
            size++;
            currentNode = currentNode->next;
        }
        return size+1;
    }
    else {
        int size = 0;
        Node<T>* currentNode = LL.head;
        while (currentNode != nullptr) {
            size++;
            currentNode = currentNode->next;
        }
        return size;
    }
}

//Iterative (Works only for non-circular Linked Lists)
//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
int lengthOfLinkedList(Node<T>* currentNode, int size=0) {
    if (currentNode != nullptr) {
        size++;
        return lengthOfLinkedList(currentNode->next, size);
    }
    return size;
}

int main() {
    LinkedList<int> LL;
    LL.addAtHead(4);
    LL.addAtHead(3);
    LL.addAtHead(2);
    LL.addAtHead(1);
    LL.print();
    std::cout<<lengthOfLinkedList(LL)<<std::endl;

    LinkedList<int> LL2(0, 1);
    LL2.addAtHead(4);
    LL2.addAtHead(3);
    LL2.addAtHead(2);
    LL2.addAtHead(1);
    LL2.print();
    std::cout<<lengthOfLinkedList(LL2)<<std::endl;
    return 0;
}
