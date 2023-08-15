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
class Queue {
	public:
	Node<T>* head; // The Rightmost Node
	Node<T>* tail; // The Leftmost Node
	
	Queue() {head = tail = nullptr;}

	bool empty() {return (head == nullptr);}

	void deQueue() {
		if (empty()) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		temp = nullptr;
	}

	void enQueue(T newElem) {
		Node<T>* newNode = new Node<T>(newElem);
		if (empty()) {
			head = tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
	}

	void enQueue(Node<T>* newNode) {
		if (empty()) {
			head = tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
	}

	void print() {
		if (empty()) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}
		Node<T>* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << " <- ";
			temp = temp->next;
		}
		std::cout << "END" << std::endl;
	}
};