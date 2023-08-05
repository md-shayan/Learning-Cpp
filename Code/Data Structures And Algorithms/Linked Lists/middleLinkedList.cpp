//Given a singly linked list, find the middle of the linked list.
//For example, if the given linked list is 1->2->3->4->5 then the output should be 3. 
#include <iostream>
#include "LinkedList.h"

//Time Compleixty: O(N)
//Space Compleixty: O(1)

template <typename T>
T getMiddleData(SinglyLinkedList<T> SLL) {
    int size = 0;
    SinglePointingNode<T>* currentNode = SLL.head;
    while (currentNode != nullptr) {
        size++;
        currentNode = currentNode->next;
    }
    int half = size/2;
    currentNode = SLL.head;
    int i=0;
    while (i<half) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}

template <typename T>
T getMiddleData(SinglyCircularLinkedList<T> SCLL) {
    int size = 1;
    SinglePointingNode<T>* currentNode = SCLL.head->next;
    while (currentNode != SCLL.head) {
        size++;
        currentNode = currentNode->next;
    }
    int half = size/2;
    currentNode = SCLL.head;
    int i=0;
    while (i<half) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}

int main() {
    SinglyLinkedList<int> SLL;
    SLL.addAtHead(6);
    SLL.addAtHead(5);   
    SLL.addAtHead(4);
    SLL.addAtHead(3);
    SLL.addAtHead(2);
    SLL.addAtHead(1);
    SLL.print();
    std::cout<<getMiddleData(SLL)<<std::endl;

    SinglyCircularLinkedList<int> SCLL;
    SCLL.addAtHead(6);
    SCLL.addAtHead(5);   
    SCLL.addAtHead(4);
    SCLL.addAtHead(3);
    SCLL.addAtHead(2);
    SCLL.addAtHead(1);
    SCLL.print();
    std::cout<<getMiddleData(SCLL)<<std::endl;
    return 0;
}