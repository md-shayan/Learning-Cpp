//Given a linked list, find the middle of the linked list.
//For example, if the given linked list is 1->2->3->4->5 then the output should be 3. 
#include <iostream>
#include "LinkedList.h"

//Time Compleixty: O(N)
//Space Compleixty: O(1)

template <typename T>
T getMiddleData(LinkedList<T> LL) {
    int size = 0;
    Node<T>* currentNode = LL.head;
    if (LL.isCircular) {
        size++;

        //Counting the number of Nodes in Linked List
        while (currentNode->next != LL.head) {
            size++;
            currentNode = currentNode->next;
        }
    }

    else {

        //Counting the number of Nodes in Linked List
        while (currentNode != nullptr) {
            size++;
            currentNode = currentNode->next;
        }
    }

    int half = size/2;
    currentNode = LL.head;
    int i=0;
    while (i<half) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}

int main() {
    LinkedList<int> LL;
    LL.addAtHead(6);
    LL.addAtHead(5);   
    LL.addAtHead(4);
    LL.addAtHead(3);
    LL.addAtHead(2);
    LL.addAtHead(1);
    LL.print();
    std::cout<<getMiddleData(LL)<<std::endl;

    LinkedList<int> LL2(0, 1);
    LL2.addAtHead(6);
    LL2.addAtHead(5);   
    LL2.addAtHead(4);
    LL2.addAtHead(3);
    LL2.addAtHead(2);
    LL2.addAtHead(1);
    LL2.print();
    std::cout<<getMiddleData(LL2)<<std::endl;
    return 0;
}