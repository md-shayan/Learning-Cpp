#include <iostream>

template <typename T>
struct Node {
        T data;
        Node<T>* next;
        Node (T setData) : data{setData} {next = nullptr;}
};

template <typename T>
class Queue {
	public:
		Node<T>* head;
		Node<T>* tail;
		Queue() {
			head = nullptr;
			tail = nullptr;
		}

		bool empty() {return head==nullptr;}

		void enQueue(T elem) {
			Node<T>* newNode = new Node<T>(elem);
			if (empty()) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail->next = newNode;
				tail = newNode;
			}
		}

		void enQueue(Node<T>* newNode) {
			if (empty()) {
                                head = newNode;
                                tail = newNode;
                        }
                        else {
                                tail->next = newNode;
                                tail = newNode;
                        }
		}

		void deQueue() {
			if (empty()) {std::cout << "Underflow!!!" << std::endl;}
			else {
				Node<T>* tempNode = head;
				head = head->next;
				tempNode = nullptr;
			}
		}

		T leftMost() {return head->data;}
		T rightMost() {return tail->data;}
};

int main() {
	Queue<int> q;
	std::cout << q.empty() << std::endl;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	std::cout << q.leftMost() << " " << q.rightMost() << std::endl;
	q.deQueue();
	std::cout << q.leftMost() << " " << q.rightMost() << std::endl;
	return 0;
}
