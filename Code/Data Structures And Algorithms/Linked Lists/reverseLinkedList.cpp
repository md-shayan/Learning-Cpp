//Given a pointer to the head node of a linked list, the task is to reverse the linked list.
//We need to reverse the list by changing the links between nodes.
#include <iostream>
#include "LinkedList.h"

//Select a Node currentNode and make currentNode->next point to the previous Node of the Linked List.
//Time Complexity: O(N)
//Space Complexity: O(1)

template <typename T>
SinglePointingNode<T>* reverseLinkedList(SinglePointingNode<T>* head) {
    SinglePointingNode<T>* currentNode = head;
    SinglePointingNode<T>* nextNode = nullptr;
    SinglePointingNode<T>* prevNode = nullptr;
    while (currentNode != nullptr) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    } 
    return prevNode;
}

template <typename T>
DoublePointingNode<T>* reverseLinkedList(DoublePointingNode<T>* head) {
    DoublePointingNode<T>* currentNode = head;
    DoublePointingNode<T>* nextNode = nullptr;
    DoublePointingNode<T>* prevNode = nullptr;
    while (currentNode != nullptr) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    } 
    return prevNode;
}

int main() {
    SinglyLinkedList<int> SLL;
    SLL.addAtHead(5);
    SLL.addAtHead(4);
    SLL.addAtHead(3);
    SLL.addAtHead(2);
    SLL.addAtHead(1);
    SLL.print();
    SLL.head = reverseLinkedList(SLL.head);
    SLL.print();
    DoublyLinkedList<char> DLL;
    DLL.addAtHead('e');
    DLL.addAtHead('d');
    DLL.addAtHead('c');
    DLL.addAtHead('b');
    DLL.addAtHead('a');
    DLL.print();
    DLL.head = reverseLinkedList(DLL.head);
    DLL.print();
    return 0;
}