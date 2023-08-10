template <typename T>
class Stack {
    T* data;
    const int maxSize;
    public:
    int totalElements = 0;
    Stack(int size) : maxSize{size} {
        data = new T[size];
    }

    // Time Complexity: O(1)
    bool isEmpty() {
        return totalElements == 0;
    }

    // Time Complexity: O(1)
    void push(T elem) {
        if (totalElements >= maxSize) {
            std::cout << "Stack is full" << std::endl;
            return;
        }
        data[totalElements] = elem;
        totalElements++;
    }

    // Time Complexity: O(1)
    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        T top = data[totalElements--];
        return top;
    }

    // Time Complexity: O(1)
    T top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        return data[totalElements - 1];
    }

    int size() {return totalElements;}

    // Time Complexity: O(N)
    void print() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        std::cout<<data[0];
        for (int i = 1; i < totalElements; i++) {
            std::cout <<  " - " << data[i];
        }
        std::cout << std::endl;
    }
};

template <typename T>
class StackNode {
    public:
    T data;
    StackNode<T>* next;
    StackNode(T data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class DynamicStack {
    StackNode<T>* topNode;
    int totalNodes = 0;
    public:
    DynamicStack() {
        topNode = nullptr;
    }

    // Time Complexity: O(1)
    bool isEmpty() {return topNode == nullptr;}

    // Time Complexity: O(1)
    void push(T data) {
        StackNode<T>* newNode = new StackNode<T>(data);
        newNode->next = topNode;
        topNode = newNode;
        totalNodes++;
    }

    // Time Complexity: O(1)
    void push(StackNode<T>* newNode) {
        newNode->next = topNode;
        topNode = newNode;
        totalNodes++;
    }

    // Time Complexity: O(1)
    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        T data = topNode->data;
        StackNode<T>* temp = topNode;
        topNode = temp->next;
        temp = nullptr;
        delete temp;
        totalNodes--;
        return data;
    }

    // Time Complexity: O(1)
    T top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        return topNode->data;
    }

    // Time Complexity: O(1)
    int size() {return totalNodes;}

    // Time Complexity: O(N)
    void print() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        StackNode<T>* temp = topNode;
        std::cout<<temp->data;
        while (temp->next!= nullptr) {
            std::cout <<  " <- " << temp->next->data;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};