template <typename T>
class Node {
	public:
	T data;
	Node<T>* next;
	Node(T set) {
		data = set;
		next = nullptr;
	}
};

template <typename T>
class Stack {
	public:
	Node<T>* topNode;
	Stack() {topNode = nullptr;}

	bool empty() {return (topNode == nullptr);}

	void push(T newElem) {
		Node<T>* newNode = new Node<T>(newElem);
		newNode->next = topNode;
		topNode = newNode;
	}


	void push(Node<T>* newNode) {
		newNode->next = topNode;
		topNode = newNode;
	}

	void pop() {
		Node<T>* temp = topNode;
		topNode = topNode->next;
		temp = nullptr;
	}

	T top() {return topNode->data;}

	void print() {
		if (empty()) {
			std::cout << "Stack is empty" << std::endl;
			return;
		}
		Node<T>* temp = topNode;
		while (temp != nullptr) {
			std::cout << temp->data << " -> ";
			temp = temp->next;
		}
		std::cout << "END" <<std::endl;
	}
};
