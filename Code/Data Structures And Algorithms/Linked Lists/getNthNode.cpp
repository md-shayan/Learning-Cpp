//Write a GetNth() function that takes a linked list and an integer index and returns the data value stored in the
//node at that index position. 
#include <iostream>
#include "LinkedList.h"

//Time Compleixty: O(N)
//Space Compleixty: O(1)

template <typename T>
T getNthNode(LinkedList<T> LL, int N) {
    int i=0;
    Node<T>* currentNode = LL.head;
    while (i < N) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}


int main() {
    LinkedList<int> LL;
    LL.addAtHead(4);
    LL.addAtHead(3);
    LL.addAtHead(2);
    LL.addAtHead(1);
    LL.print();
    std::cout<<getNthNode<int>(LL, 2)<<std::endl;

    LinkedList<int> LL2(0, 1);
    LL2.addAtHead(4);
    LL2.addAtHead(3);
    LL2.addAtHead(2);
    LL2.addAtHead(1);
    LL2.print();
    std::cout<<getNthNode<int>(LL2, 2)<<std::endl;
    return 0;
}