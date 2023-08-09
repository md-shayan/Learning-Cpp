//Given a circular linked list, count the number of nodes in it.
#include <iostream>
#include "LinkedList.h"

template <typename T>
int countNodes(LinkedList<T> ll) {
    if (ll.isCircular) {
        int count = 0;
        Node<T>* currentNode = ll.head;
        while (currentNode->next != ll.head) {
            count++;
            currentNode = currentNode->next;
        }
        return count+1;
    }
    else {
        int count = 0;
        Node<T>* currentNode = ll.head;
        while (currentNode != nullptr) {
            count++;
            currentNode = currentNode->next;
        }
        return count;
    }
}

int main() {
    LinkedList<int> ll;
    ll.addAtHead(4);
    ll.addAtHead(3);
    ll.addAtHead(2);
    ll.addAtHead(1);
    ll.print();
    std::cout<<countNodes(ll)<<std::endl;

    LinkedList<int> ll2(0, 1);
    ll2.addAtHead(4);
    ll2.addAtHead(3);
    ll2.addAtHead(2);
    ll2.addAtHead(1);
    ll2.print();
    std::cout<<countNodes(ll2)<<std::endl;
    return 0;
}