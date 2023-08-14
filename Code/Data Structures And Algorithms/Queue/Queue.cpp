#include <iostream>
#include <climits>

template <typename T>
class Queue {
	public:
	T* queue;
	const int maxSize;
	int totalElem = 0;
	Queue(int maxSize=INT_MAX) : maxSize{maxSize} {
		queue = new T[maxSize];
	}
	Queue(T* arr, int size, int maxSize=INT_MAX) : maxSize{maxSize} {
		if (size > maxSize) {
			std::cout << "Queue has more elements than storage allocated for it" << std::endl;
			return;
		}
		queue = arr;
		totalElem = size;
	}

	bool empty() {return (totalElem == 0);}
	bool full() {return (totalElem == maxSize);}

	void deQueue() {
		if (empty()) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}
		totalElem--;	
	}

	T front() {return queue[totalElem-1];}

	T rear() {return queue[0];}

	// Time Complexity: O(N)
	void enQueue(T newElem) {
		if (full()) {
			std::cout << "Queue is full" << std::endl;
			return;
		}

		// Push all the elements to the right by one
		int i=totalElem;
		while (i >= 0) {
			queue[i+1] = queue[i];
			i--;
		}
		queue[0] = newElem;
		totalElem++;
	}
};

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(T setData) : data{setData} {
		next = nullptr;
	}
};

/*
template <typename T>
class DynamicQueue {
	public:
	Node<T>* tail;
	Node<T>* head;
	DynamicQueue() {
		tail = nullptr;
		head = nullptr;
	}

	bool empty() {return (tail == nullptr);}
	
	T peek() {return head->data;}
	T rear() {return tail->data;}
	
	void deQueue() {
		if (empty()) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}
		Node<T>* prevNode = tail;
		while (prevNode->next->next != nullptr) {
			prevNode = prevNode->next;
		}
		head = prevNode;
		head->next = nullptr;
	}

	void enQueue(T elem) {
		Node<T>* newNode = new Node<T>(elem);
		if (empty()) {
			tail = newNode;
			head = tail->next;
			return;
		}
		newNode->next = tail;
		tail = newNode;
		head = tail->next;
	}

	void enQueue(Node<T>* newNode) {
		if (empty()) {
			tail = newNode;
			return;
		}
		newNode->next = tail;
		tail = newNode;
	}

	void print() {
		if (empty()) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}
		Node<T>* current = tail;
		while (current != nullptr) {
			std::cout << current->data << " -> ";
			current = current->next;
		}
		std::cout << "END" << std::endl;
	}

};
*/
