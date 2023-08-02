#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T d) : data{d} {
        next = nullptr;
    }
};

template <typename T>
struct SinglyLinkedList {
    Node<T>* head;
    SinglyLinkedList() {
        this->head = nullptr;
    }

    //Time Complexity: O(1)
    void addAtHead(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
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
    }

    //Time Compleixty: O(N)
    void addAfter(Node<T>* prevNode, T data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* nextNode = head;
        while (prevNode->next != nextNode) {
            nextNode = nextNode->next;
        }
        newNode->next = nextNode;
        prevNode->next = newNode;
    }

    //Time Compleixty: O(N)
    void addBefore(Node<T>* nextNode, T data) {
        Node<T>* newNode = new Node<T>(data);
        if (nextNode == head) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node<T>* prevNode = head;
        while (prevNode->next != nextNode) {
            prevNode = prevNode->next;
        }
        newNode->next = nextNode;
        prevNode->next = newNode;
    }

    Node<T>* getNode(T data) {
        Node<T>* currentNode = head;
        while (currentNode->data != data && currentNode != nullptr) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }

    void print() {
        Node<T>* currentNode = head;
        if (head == nullptr) {
            std::cout<<"Empty List"<<std::endl;
            return;
        }
        while (currentNode != nullptr) {
            std::cout<<currentNode->data<<" -> ";
            currentNode = currentNode->next;
        }
        std::cout<<"NULL"<<std::endl;
    }
};