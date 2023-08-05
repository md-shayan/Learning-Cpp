//Write a GetNth() function that takes a linked list and an integer index and returns the data value stored in the
//node at that index position. 
#include <iostream>
#include "LinkedList.h"

//Time Compleixty: O(N)
//Space Compleixty: O(1)

template <typename T>
T getNthNode(SinglyLinkedList<T> SLL, int N) {
    int i=0;
    SinglePointingNode<T>* currentNode = SLL.head;
    while (i < N) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}

template <typename T>
T getNthNode(DoublyLinkedList<T> DLL, int N) {
    int i=0;
    DoublePointingNode<T>* currentNode = DLL.head;
    while (i < N) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}
template <typename T>
T getNthNode(SinglyCircularLinkedList<T> SCLL, int N) {
    int i=0;
    SinglePointingNode<T>* currentNode = SCLL.head;
    while (i < N) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}
template <typename T>
T getNthNode(DoublyCircularLinkedList<T> DCLL, int N) {
    int i=0;
    DoublePointingNode<T>* currentNode = DCLL.head;
    while (i < N) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}

int main() {
    SinglyLinkedList<int> SLL;
    SLL.addAtHead(4);
    SLL.addAtHead(3);
    SLL.addAtHead(2);
    SLL.addAtHead(1);
    SLL.print();
    std::cout<<getNthNode<int>(SLL, 2);
    return 0;
}