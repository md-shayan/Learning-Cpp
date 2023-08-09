//Given a pointer to the head node of a linked list, the task is to reverse the linked list.
//We need to reverse the list by changing the links between nodes.
#include <iostream>
#include "LinkedList.h"

//Select a Node currentNode and make currentNode->next point to the previous Node of the Linked List.
//Time Complexity: O(N)
//Space Complexity: O(1)

template <typename T>
Node<T>* reverseLinkedList(Node<T>* head, bool isCircular) {
    Node<T>* currentNode = head;
    Node<T>* nextNode = nullptr;
    Node<T>* prevNode = nullptr;

    if (isCircular) {
        while (currentNode->next != head) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        head->next = prevNode;
        head = prevNode;
    }

    else {
            while (currentNode != nullptr) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        } 
    }
    return prevNode;
}

int main() {
    LinkedList<int> LL;
    LL.addAtHead(5);
    LL.addAtHead(4);
    LL.addAtHead(3);
    LL.addAtHead(2);
    LL.addAtHead(1);
    LL.print();
    LL.head = reverseLinkedList(LL.head, LL.isCircular);
    LL.print();
    LinkedList<char> LL2(0, 1);
    LL2.addAtHead('e');
    LL2.addAtHead('d');
    LL2.addAtHead('c');
    LL2.addAtHead('b');
    LL2.addAtHead('a');
    LL2.print();
    LL2.head = reverseLinkedList(LL2.head, LL2.isCircular);
    LL2.print();
    return 0;
}