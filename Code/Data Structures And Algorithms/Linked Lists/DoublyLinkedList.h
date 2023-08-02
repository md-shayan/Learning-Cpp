#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(T d) : data{d} {
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
struct DoublyLinkedList {
    Node<T>* head;
    DoublyLinkedList() {
        head = nullptr;
    }

    //Time Complexity: O(1)
    void addAtHead(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    //Time Complexity: O(N)
    void addAtTail(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* tailNode = head;
        while (tailNode->next != nullptr) {
            tailNode = tailNode->next;
        }
        tailNode->next = newNode;
        newNode->prev = tailNode;
    }

    //Time Complexity: O(1)
    void addAfter(Node<T>* prevNode, T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
    }

    //Time Complexity: O(1)
    void addBefore(Node<T>* nextNode, T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->prev = nextNode->prev;
        nextNode->prev = newNode;
        newNode->next = nextNode;
        if (newNode->prev != nullptr) {
            newNode->prev->next = newNode;
        }
        else {
            head = newNode;
        }
    }

    void print() {
        Node<T>* currentNode = head;
        if (head == nullptr) {
            std::cout<<"Empty List"<<std::endl;
            return;
        }
        while (currentNode != nullptr) {
            std::cout<<currentNode->data<<" <-> ";
            currentNode = currentNode->next;
        }
        std::cout<<"NULL"<<std::endl;
    }

    Node<T>* getNode(T data) {
        Node<T>* currentNode = head;
        while (currentNode->data != data) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
};