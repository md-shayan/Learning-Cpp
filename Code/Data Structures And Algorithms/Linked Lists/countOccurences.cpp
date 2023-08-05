//Given a singly linked list and a key, count the number of occurrences of the given key in the linked list.
#include <iostream>
#include "LinkedList.h"

//Time Complexity: O(N)
//Space Complexity: O(1)

template <typename T>
int countOccurences(SinglyLinkedList<T> SLL, T key) {
    int occurences = 0;
    SinglePointingNode<T>* currentNode = SLL.head;
    while (currentNode) {
        if (currentNode->data == key) {
            occurences++;
        }
        currentNode = currentNode->next;
    }
    return occurences;
}

template <typename T>
int countOccurences(SinglyCircularLinkedList<T> SCLL, T key) {
    int occurences = 0;
    if (SCLL.head) {occurences = 1;}
    SinglePointingNode<T>* currentNode = SCLL.head->next;
    while (currentNode != SCLL.head) {
        if (currentNode->data == key) {
            occurences++;
        }
        currentNode = currentNode->next;
    }
    return occurences;
}

int main() {
    SinglyLinkedList<int> SLL;
    SLL.addAtHead(1);
    SLL.addAtHead(3);
    SLL.addAtHead(1);
    SLL.addAtHead(2);
    SLL.addAtHead(1);
    SLL.addAtHead(2);
    SLL.addAtHead(1);
    SLL.print();
    std::cout<<countOccurences(SLL, 1)<<std::endl;

    SinglyCircularLinkedList<int> SCLL;
    SCLL.addAtHead(1);
    SCLL.addAtHead(3);
    SCLL.addAtHead(1);
    SCLL.addAtHead(2);
    SCLL.addAtHead(1);
    SCLL.addAtHead(2);
    SCLL.addAtHead(1);
    SCLL.print();
    std::cout<<countOccurences(SCLL, 1)<<std::endl;
    return 0;
}