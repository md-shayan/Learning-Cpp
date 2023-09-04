#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node(T setElem) : data{setElem} {next = nullptr;}
};

template <typename T>
class Set {
	public:
		Node<T>* head;
		Node<T>* tail;
		Set() {
			head = nullptr;
			tail = nullptr;
		}

		bool empty() {return head == nullptr;}

		void push(T elem) {
			Node<T>* newNode = new Node<T>(elem);
			if (empty()) {head = newNode;}
			else {tail->next = newNode;}
			tail = newNode;
		}

		void push(Node<T>* newNode) {
			if (empty()) {head = newNode;}
                        else {tail->next = newNode;}
                        tail = newNode;
		}

		void pop() {
			if (empty()) {std::cout << "Underflow!!!" << std::endl;}
			else {
				Node<T>* tempNode = head;
				head = head->next;
				tempNode = nullptr;
			}
		}

		T front() {return head->data;}
		T back() {return tail->data;}
};

template <typename T>
Set<T> Union(Set<T>& S1, Set<T>& S2) {
	S1.tail->next = S2.head;
	Set<T> S;
	S.head = S1.head;
	S.tail = S2.tail;
	return S;
}

int main() {
	Set<int> S1;
	S1.push(1);
	S1.push(2);
	std::cout << S1.front() << " " << S1.back() << std::endl;

	Set<int> S2;
	S2.push(3);
	S2.push(4);
	std::cout << S2.front() << " " << S2.back() << std::endl;


	Set<int> S = Union<int>(S1, S2);
	std::cout << S.front() << " " << S.back() << std::endl;
	return 0;
}
