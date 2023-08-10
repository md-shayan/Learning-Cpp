template <typename T>
class Node {
    public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T setData) : data{setData} {
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class LinkedList {


    public:
    Node<T>* head;

    // Changing this would not make a circular list into non-circular, or vice versa
    // Hence it is declared const for safety and will only be used by the class methods
    const bool isCircular;

    // Unlike isCircular, changing this would impact how the 'print()' method prints this linked list
    // Instead of ' -> ', isDoubly would make it ' <-> ' to show a two way connection between Nodes
    bool isDoubly;

    LinkedList(bool setDoubly=false, bool setCircular=false) : isCircular{setCircular} {
        head = nullptr;
        isDoubly = setDoubly;
    }

    bool isEmpty() {
        return (head==nullptr);
    }


    void addAtHead(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head=newNode;

            // Self-explanatory corner case
            if (isCircular) {head->next = head;}
            // For non-circular linked lists,
            // The prev of head Node will always be NULL 
            return;
        }
        newNode->next = head;
        if (isDoubly) {head->prev = newNode;}

        // An important condition for circular linked lists,
        // Making the last Node of the linked list point next to newNode
        if (isCircular) {
            Node<T>* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
            if (isDoubly) {newNode->prev = lastNode;}
        }
        head = newNode;
    }

    void addAtHead(Node<T>* newNode) {
        if (isEmpty()) {
            head=newNode;

            // Self-explanatory corner case
            if (isCircular) {head->next = head;}
            // For non-circular linked lists,
            // The prev of head Node will always be NULL 
            return;
        }
        newNode->next = head;
        if (isDoubly) {head->prev = newNode;}

        // An important condition for circular linked lists,
        // Making the last Node of the linked list point next to newNode
        if (isCircular) {
            Node<T>* lastNode = head;
            while (lastNode->next != head) {lastNode = lastNode->next;}
            lastNode->next = newNode;
            if (isDoubly) {newNode->prev = lastNode;}
        }
        head = newNode;
    }

    void addAtTail(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            head = newNode;

            // Self-explanatory corner case
            if (isCircular) {head->next = head;}
            // For non-circular linked lists,
            // The prev of head Node will always be NULL 
            return;
        }
        Node<T>* lastNode = head;
        if (isCircular) {
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }

            // The terminating conditon of circular linked lists
            newNode->next = head;
        }
        else {
            while (lastNode->next != nullptr) {
                lastNode = lastNode->next;
            }
        }
        lastNode->next = newNode;
        if (isDoubly) {newNode->prev = lastNode;}
    }

    void addAtTail(Node<T>* newNode) {
        if (isEmpty()) {
            head = newNode;

            // Self-explanatory corner case
            if (isCircular) {head->next = head;}
            // For non-circular linked lists,
            // The prev of head Node will always be NULL 
            return;
        }
        Node<T>* lastNode = head;
        if (isCircular) {
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }

            // The terminating conditon of circular linked lists
            newNode->next = head;
        }
        else {
            while (lastNode->next != nullptr) {
                lastNode = lastNode->next;
            }
        }
        lastNode->next = newNode;
        if (isDoubly) {newNode->prev = lastNode;}
    }

    void addAfter(Node<T>* prevNode, T data) {
        if (isEmpty() || prevNode == nullptr) {
            std::cout<<"Node is a nullptr and/or List is empty"<<std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        // If prev Node is the last Node of:
        // CASE 1: A circular linked list
        if (isCircular && prevNode->next == head) {
            newNode->next = prevNode->next;
            prevNode->next = newNode;
            if (isDoubly) {newNode->prev = prevNode;}
            return;
        }

        // CASE 2: A non-circular linked list
        if (!isCircular && prevNode->next == nullptr) {
            prevNode->next = newNode;
            if (isDoubly) {newNode->prev = prevNode;}
            return;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    void addAfter(Node<T>* prevNode, Node<T>* newNode) {
        if (isEmpty() || prevNode == nullptr || newNode == nullptr) {
            std::cout<<"Node is a nullptr and/or List is empty"<<std::endl;
            return;
        }

        // If prev Node is the last Node of:
        // CASE 1: A circular linked list
        if (isCircular && prevNode->next == head) {
            newNode->next = prevNode->next;
            prevNode->next = newNode;
            if (isDoubly) {newNode->prev = prevNode;}
            return;
        }

        // CASE 2: A non-circular linked list
        if (!isCircular && prevNode->next == nullptr) {
            prevNode->next = newNode;
            if (isDoubly) {newNode->prev = prevNode;}
            return;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    void addBefore(Node<T>* nextNode, T data) {
        if (isEmpty() || nextNode == nullptr) {
            std::cout<<"Node is a nullptr and/or List is empty"<<std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        if (nextNode == head) {
            newNode->next = nextNode;

            // If the linked list is circular, then point the last Node next to new Node
            if (isCircular) {
                Node<T>* lastNode = head;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }
                lastNode->next = newNode;
            }
            if (isDoubly) {nextNode->prev = newNode;}
            head = newNode;
            return;
        }
        Node<T>* prevNode;
        if (isDoubly) {prevNode = nextNode->prev;}
        else {
            prevNode = head;
            while (prevNode->next != nextNode) {
                prevNode = prevNode->next;
            }
        }
        prevNode->next = newNode;
        newNode->next = nextNode;
        if (isDoubly) {
            nextNode->prev = newNode;
            newNode->prev = prevNode;
        }
    }

    void addBefore(Node<T>* nextNode, Node<T>* newNode) {
        if (isEmpty() || nextNode == nullptr || newNode == nullptr) {
            std::cout<<"Node is a nullptr and/or List is empty"<<std::endl;
            return;
        }

        if (nextNode == head) {
            newNode->next = nextNode;

            // If the linked list is circular, then point the last Node next to new Node
            if (isCircular) {
                Node<T>* lastNode = head;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }
                lastNode->next = newNode;
            }
            if (isDoubly) {nextNode->prev = newNode;}
            head = newNode;
            return;
        }
        Node<T>* prevNode;
        if (isDoubly) {prevNode = nextNode->prev;}
        else {
            prevNode = head;
            while (prevNode->next != nextNode) {
                prevNode = prevNode->next;
            }
        }
        prevNode->next = newNode;
        newNode->next = nextNode;
        if (isDoubly) {
            nextNode->prev = newNode;
            newNode->prev = prevNode;
        }
    }

    // Deletes the first Node containing 'data'
    void deleteNode(T data) {
        if (isEmpty()) {
            std::cout<<"Linked List is empty"<<std::endl;
            return;
        }

        Node<T>* NodeToDelete = getNode(data);
        if (NodeToDelete == nullptr) {
            std::cout<<"Node with 'data' not found"<<std::endl;
            return;
        }

        // Point the next of prev Node to next of NodeToDelete
        Node<T>* prevNode = head;
        while (prevNode->next != NodeToDelete) {
            prevNode = prevNode->next;
        }
        prevNode->next = NodeToDelete->next;
        if (NodeToDelete == head) {
            head = NodeToDelete->next;
            if (isDoubly) {head->prev = nullptr;}
        }
        if (isDoubly) {NodeToDelete->next->prev = prevNode;}
        NodeToDelete = nullptr;
        delete NodeToDelete;
    }

    // Deletes the given Node
    void deleteNode(Node<T>* NodeToDelete) {
        if (isEmpty()) {
            std::cout<<"Linked List is empty"<<std::endl;
            return;
        }

        if (NodeToDelete == nullptr) {
            std::cout<<"Node with 'data' not found"<<std::endl;
            return;
        }

        // The above implementation of LinkedList<T>::deleteNode(T) does not require this
        // as it iterates over the list using LinkedList<T>::getNode(T) function which
        // does the same job.
        if (!exists(NodeToDelete)) {
            return;
        }

        // Point the next of prev Node to next of NodeToDelete
        Node<T>* prevNode = head;
        while (prevNode->next != NodeToDelete) {
            prevNode = prevNode->next;
        }
        prevNode->next = NodeToDelete->next;
        if (NodeToDelete == head) {
            head = NodeToDelete->next;
            if (isDoubly) {head->prev = nullptr;}
        }
        if (isDoubly) {NodeToDelete->next->prev = prevNode;}
        NodeToDelete = nullptr;
        delete NodeToDelete;
    }

    // Returns the first Node containing 'data',
    // If none then returns NULL
    Node<T>* getNode(T data) {
        if (isEmpty()) {return nullptr;}

        Node<T>* NodeToGet = head;
        if (isCircular) {
            while (NodeToGet->data != data) {

                // Indicates the end of a circular linked list, hence it terminates
                if (NodeToGet->next == head) {return nullptr;}
                NodeToGet = NodeToGet->next;
            }
            return NodeToGet;
        }
        while (NodeToGet->data != data) {

            // Indicates the end of a non-circular linked list, hence it terminates
            if (NodeToGet->next == nullptr) {return nullptr;}
            NodeToGet = NodeToGet->next;
        }
        return NodeToGet;
    }

    //return true of NodeToSearch exists in the Linked List
    bool exists(Node<T>* NodeToSearch) {
        if (head == nullptr) {
            std::cout<<"Linked List is Empty"<<std::endl;
            return false;
        }

        if (NodeToSearch == nullptr) {
            std::cout<<"Cannot Search NULL in Linked List"<<std::endl;
            return false;
        }

        Node<T>* currentNode = head;
        if (isCircular) {
            while (currentNode != NodeToSearch) {
                if (currentNode->next == head) {return false;}
                currentNode = currentNode->next;
            }
            return true;
        }
        while (currentNode != NodeToSearch) {
            if (currentNode->next == nullptr) {return false;}
            currentNode = currentNode->next;
        }
        return true;
    }

    void print() {
        if (isEmpty()) {
            std::cout<<"Empty List"<<std::endl;
            return;
        }
        Node<T>* currentNode;

        // For circular linked lists, the terminating condition is that last Node points next to head Node
        if (isCircular) {
            std::cout<<head->data;
            if (head->next == head) {
                std::cout<<head->data<<std::endl;
                return;
            }
            currentNode = head->next;
            while (currentNode != head) {
                if (isDoubly) {std::cout<<" <-> "<<currentNode->data;}
                else {std::cout<<" -> "<<currentNode->data;}
                    currentNode = currentNode->next;
                }
            if (isDoubly) {std::cout<<" <-> "<<head->data<<std::endl;}
            else {std::cout<<" -> "<<head->data<<std::endl;}
        }

        // For non-circular linked lists, the condition is that last Node points next to NULL
        else {
            currentNode = head;
            while (currentNode->next != nullptr) {
                if (isDoubly) {std::cout<<currentNode->data<<" <-> ";}
                else {std::cout<<currentNode->data<<" -> ";}
                currentNode = currentNode->next;
            }
            std::cout<<currentNode->data<<std::endl;
        }
    }
};
