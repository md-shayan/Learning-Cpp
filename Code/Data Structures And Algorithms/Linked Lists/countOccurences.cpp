//Given a singly linked list and a key, count the number of occurrences of the given key in the linked list.
#include <iostream>
#include "LinkedList.h"

//Time Complexity: O(N)
//Space Complexity: O(1)
template <typename T>
int countOccurences(LinkedList<T> LL, T key) {
    int occurences = 0;
    Node<T>* currentNode = LL.head;
    if (LL.isCircular) {
        while (currentNode->next != LL.head) {
            if (currentNode->data == key) {occurences++;}
            currentNode = currentNode->next;
        }
        return occurences+1;
    }
    else {
            while (currentNode != nullptr) {
            if (currentNode->data == key) {occurences++;}
            currentNode = currentNode->next;
        }
        return occurences;
    }
}

int main() {
    LinkedList<int> LL;
    LL.addAtHead(1);
    LL.addAtHead(3);
    LL.addAtHead(1);
    LL.addAtHead(2);
    LL.addAtHead(1);
    LL.addAtHead(2);
    LL.addAtHead(1);
    LL.print();
    std::cout<<countOccurences(LL, 1)<<std::endl;

    LinkedList<int> LL2(0, 1);
    LL2.addAtHead(1);
    LL2.addAtHead(3);
    LL2.addAtHead(1);
    LL2.addAtHead(2);
    LL2.addAtHead(1);
    LL2.addAtHead(2);
    LL2.addAtHead(1);
    LL2.print();
    std::cout<<countOccurences(LL2, 1)<<std::endl;
    return 0;
}