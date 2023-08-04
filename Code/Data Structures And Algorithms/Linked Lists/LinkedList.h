#include <iostream>

template <typename T>
struct SinglePointingNode {
    T data;
    SinglePointingNode<T>* next;
    SinglePointingNode(T data) : data{data} {
        next = nullptr;
    }
};

template <typename P>
struct DoublePointingNode {
    P data;
    DoublePointingNode<P>* next;
    DoublePointingNode<P>* prev;
    DoublePointingNode(P data) : data{data} {
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
struct SinglyLinkedList {
    SinglePointingNode<T>* head;
    SinglyLinkedList() {
        this->head = nullptr;
    }

    //Time Complexity: O(1)
    void addAtHead(T data) {
        SinglePointingNode<T>* newNode = new SinglePointingNode<T>(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }

    //Time Complexity: O(N)
    void addAtTail(T data) {
        SinglePointingNode<T>* newNode = new SinglePointingNode<T>(data);
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        SinglePointingNode<T>* tailNode = head;
        while (tailNode->next != nullptr) {
            tailNode = tailNode->next;
        }
        tailNode->next = newNode;
    }

    //Time Compleixty: O(N)
    void addAfter(SinglePointingNode<T>* prevNode, T data) {
        SinglePointingNode<T>* newNode = new SinglePointingNode<T>(data);
        SinglePointingNode<T>* nextNode = head;
        while (prevNode->next != nextNode) {
            nextNode = nextNode->next;
        }
        newNode->next = nextNode;
        prevNode->next = newNode;
    }

    //Time Compleixty: O(N)
    void addBefore(SinglePointingNode<T>* nextNode, T data) {
        SinglePointingNode<T>* newNode = new SinglePointingNode<T>(data);
        if (nextNode == head) {
            newNode->next = head;
            head = newNode;
            return;
        }
        SinglePointingNode<T>* prevNode = head;
        while (prevNode->next != nextNode) {
            prevNode = prevNode->next;
        }
        newNode->next = nextNode;
        prevNode->next = newNode;
    }

    SinglePointingNode<T>* getNode(T data) {
        SinglePointingNode<T>* currentNode = head;
        while (currentNode->data != data && currentNode != nullptr) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }

    //Time Complexity: O(N)
    void deleteNode(T data) {
        if (head == nullptr) {
            return;
        }
        SinglePointingNode<T>* NodeToDelete = getNode(data);
        if (NodeToDelete == head) {
            SinglePointingNode<T>* tempNode = head->next;
            delete NodeToDelete;
            head = tempNode;
            return;
        }
        SinglePointingNode<T>* prevNode = head;
        while (prevNode->next != NodeToDelete) {
            prevNode = prevNode->next;
        }
        prevNode->next = NodeToDelete->next;
        delete NodeToDelete;
    }

    void print() {
        SinglePointingNode<T>* currentNode = head;
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

template <typename P>
struct DoublyLinkedList {
    public:
    DoublePointingNode<P>* head;
    DoublyLinkedList() {
        head = nullptr;
    }

    //Time Complexity: O(1)
    void addAtHead(P data) {
        DoublePointingNode<P>* newNode = new DoublePointingNode<P>(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    //Time Complexity: O(N)
    void addAtTail(P data) {
        DoublePointingNode<P>* newNode = new DoublePointingNode<P>(data);
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DoublePointingNode<P>* tailNode = head;
        while (tailNode->next != nullptr) {
            tailNode = tailNode->next;
        }
        tailNode->next = newNode;
        newNode->prev = tailNode;
    }

    //Time Complexity: O(1)
    void addAfter(DoublePointingNode<P>* prevNode, P data) {
        DoublePointingNode<P>* newNode = new DoublePointingNode<P>(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
    }

    //Time Complexity: O(1)
    void addBefore(DoublePointingNode<P>* nextNode, P data) {
        DoublePointingNode<P>* newNode = new DoublePointingNode<P>(data);
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

    //Time Complexity: O(N)
    void deleteNode(P data) {
        if (head == nullptr) {
            return;
        }
        DoublePointingNode<P>* NodeToDelete = getNode(data);
        if (NodeToDelete == head) {
            DoublePointingNode<P>* tempNode = head->next;
            delete NodeToDelete;
            head = tempNode;
            return;
        }
        DoublePointingNode<P>* prevNode = NodeToDelete->prev;
        prevNode->next = NodeToDelete->next;
        delete NodeToDelete;
        return;
    }

    //Time Complexity: O(N)
    DoublePointingNode<P>* getNode(P data) {
        DoublePointingNode<P>* currentNode = head;
        while (currentNode->data != data) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }

    void print() {
        DoublePointingNode<P>* currentNode = head;
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

};

template <typename T>
struct SinglyCircularLinkedList {
    SinglePointingNode<T>* head;
    SinglyCircularLinkedList() {
        head = nullptr;
    }

    //Time Complexity: O(N)
    void addAtHead(T data) {
        SinglePointingNode<T>* newNode = new SinglePointingNode<T>(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        SinglePointingNode<T>* lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    //Time Complexity: O(N)
    void addAtTail(T data) {
        SinglePointingNode<T>* newNode = new SinglePointingNode<T>(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        SinglePointingNode<T>* lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = head;
    }

    //Time Complexity: O(1)
    void addAfter(SinglePointingNode<T>* prevNode, T data) {
        SinglePointingNode<T>* newNode = new SinglePointingNode<T>(data);
        if (head == nullptr) {
            head = newNode;
            head->next = newNode;
            return;
        }
        SinglePointingNode<T>* nextNode = prevNode->next;
        prevNode->next = newNode;
        newNode->next = nextNode;
    }

    //Time Complexity: O(N)
    void addBefore(SinglePointingNode<T>* nextNode, T data) {
        SinglePointingNode<T>* newNode = new SinglePointingNode<T>(data);
        if (head == nullptr) {
            head = newNode;
            head->next = newNode;
            return;
        }
        SinglePointingNode<T>* prevNode = head;
        while (prevNode->next != nextNode) {
            prevNode = prevNode->next;
        }
        prevNode->next = newNode;
        newNode->next = nextNode;
    }

    //Time Complexity: O(N)
    SinglePointingNode<T>* getNode(T data) {
        SinglePointingNode<T>* currentNode = head;
        while (currentNode->data != data) {
            currentNode = currentNode->next;
            if (currentNode == head) {
                return nullptr;
            }
        }
        return currentNode;
    }

    //Time Complexity: O(N)
    void deleteNode(T data) {
        if (head == nullptr) {
            return;
        }
        SinglePointingNode<T>* NodeToDelete = getNode(data);
        if (NodeToDelete == nullptr) {
            std::cout<<"Given SinglePointingNode is not Found"<<std::endl;
            
        }
        if (NodeToDelete == head) {
            SinglePointingNode<T>* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            lastNode->next = NodeToDelete->next;
            head = NodeToDelete->next;
            delete NodeToDelete;
            return;
        }
        SinglePointingNode<T>* prevNode = head;
        while (prevNode->next != NodeToDelete) {
            prevNode = prevNode->next;
        }
        prevNode->next = NodeToDelete->next;
        delete NodeToDelete;
    }

    void print() {
        if (head == nullptr) {
            std::cout<<"Empty List"<<std::endl;
            return;
        }
        if (head->next == head) {
            std::cout<<head->data<<" -> "<<head->data<<std::endl;
            return;
        }
        std::cout<<head->data<<" -> ";
        SinglePointingNode<T>* currentNode = head->next;
        while (currentNode != head) {
            std::cout<<currentNode->data<<" -> ";
            currentNode = currentNode->next;
        }
        std::cout<<head->data<<std::endl;
    }
};

template <typename P>
struct DoublyCircularLinkedList {
    public:
    DoublePointingNode<P>* head;

    DoublyCircularLinkedList() {
        head = nullptr;
    }

    //Time Complexity: O(1)
    void addAtHead(P data) {
        DoublePointingNode<P>* newNode = new DoublePointingNode<P>(data);
        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }
        DoublePointingNode<P>* lastNode = head->prev;
        lastNode->next = newNode;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = lastNode;
        head = newNode;
    }

    //Time Complexity: O(1)
    void addAtTail(P data) {
        DoublePointingNode<P>* newNode = new DoublePointingNode<P>(data);
        if (head == nullptr) {
            newNode->prev = newNode;
            newNode->next = newNode;
            head = newNode;
            return;
        }
        DoublePointingNode<P>* lastNode = head->prev;
        lastNode->next = newNode;
        newNode->next = head;
        newNode->prev = lastNode;
        head->prev = newNode;
        newNode->prev = lastNode;
    }

    //Time Complexity: O(1)
    void addAfter(DoublePointingNode<P>* prevNode, P data) {
        DoublePointingNode<P>* newNode = new DoublePointingNode<P>(data);
        DoublePointingNode<P>* nextNode = prevNode->next;
        if (nextNode == head) {
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    //Time Complexity: O(1)
    void addBefore(DoublePointingNode<P>* nextNode, P data) {
        if (head == nullptr) {
            std::cout<<"List is empty"<<std::endl;
            return;
        }
        DoublePointingNode<P>* newNode = new DoublePointingNode<P>(data);
        DoublePointingNode<P>* prevNode = nextNode->prev;
        if (nextNode == head) {
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    //Time Compleixty: O(1)
    void deleteNode(P data) {
        DoublePointingNode<P>* NodeToDelete = getNode(data);
        DoublePointingNode<P>* prevNode = NodeToDelete->prev;
        if (NodeToDelete == head) {
            prevNode->next = head->next;
            head = head->next;
            delete NodeToDelete;
            return;
        }
        prevNode->next = NodeToDelete->next;
        NodeToDelete->next->prev = prevNode;
        delete NodeToDelete;
        return;
    }

    DoublePointingNode<P>* getNode(P data) {
        if (head->data == data) {
            return head;
        }
        DoublePointingNode<P>* currentNode = head->next;
        while(currentNode->data != data && currentNode != head) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }

    void print() {
        if (head == nullptr) {
            std::cout<<"Empty List"<<std::endl;
            return;
        }
        std::cout<<head->data<<" <-> ";
        DoublePointingNode<P>* currentNode = head->next;
        while (currentNode != head) {
            std::cout<<currentNode->data<<" <-> ";
            currentNode = currentNode->next;
        }
        std::cout<<head->data<<std::endl;
    }
};