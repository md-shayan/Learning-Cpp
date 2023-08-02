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
struct CircularLinkedList {
    Node<T>* head;
    CircularLinkedList() {
        head = nullptr;
    }

    void AddAtHead(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node<T>* currentNode = head;
        while (currentNode->next != head) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        newNode->next = head;
    }

    void print() {
        if (head == nullptr) {
            std::cout<<"Empyt List"<<std::endl;
            return;
        }
        std::cout<<head->data<<" -> ";
        Node<T>* currentNode = head->next;
        while (currentNode != head) {
            std::cout<<currentNode->data<<" -> ";
            currentNode = currentNode->next;
        }
        std::cout<<head->data<<std::endl;
    }
};