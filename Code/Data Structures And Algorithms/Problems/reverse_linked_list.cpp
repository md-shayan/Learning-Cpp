#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	
	Node(T setData) : data{setData} {next = nullptr;}
};

template <typename T>
class Singly_Linked_List {
	public:
		Node<T>* head;
		Node<T>* tail;
		Singly_Linked_List() {
			head = nullptr;
			tail = nullptr;
		}

		bool empty() {return head==nullptr;}

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
			if (empty()) {return;}
			Node<T>* tempNode = head;
			head = head->next;
			tempNode = nullptr;
		}
};

template <typename T>
void reverse_linked_list(Singly_Linked_List<T>& SLL) {
	Node<T> *prevNode, *currentNode, *nextNode;
	prevNode = nullptr;
	currentNode = SLL.head;
	while (currentNode != nullptr) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	SLL.head = prevNode;
}

int main() {
	Singly_Linked_List<int> SLL;
	SLL.push(0);
	SLL.push(1);
	SLL.push(2);
	SLL.push(3);
	SLL.push(4);
	SLL.pop();
	
	std::cout << SLL.head->data << std::endl;
	reverse_linked_list<int>(SLL);

	std::cout << SLL.head->data << std::endl;
	return 0;
}
