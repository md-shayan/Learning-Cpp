#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node (T setData) : data{setData} {next = nullptr;}
};

template <typename T>
class Stack {
	public:
		Node<T>* head;
		Stack() {head = nullptr;}

		bool empty() {return head==nullptr;}

		void push(T elem) {
			Node<T>* newNode = new Node<T>(elem);
			if (empty()) {head=newNode;}
			else {
				newNode->next = head;
				head = newNode;
			}
		}

		void push(Node<T>* newNode) {
			if (empty()) {head=newNode;}
                        else {
                        	newNode->next = head;
                                head = newNode;

                        }
		}

		void pop() {
			if (empty()) {std::cout << "Underflow!!!" << std::endl;}
			else {
				Node<T>* tempNode = head;
				head = head->next;
				tempNode = nullptr;
			}
		}

		T top() {return head->data;}
};

int main() {
	Stack<int> st;
	std::cout << st.empty() << std::endl;
	st.push(1);
	std::cout << st.top() << std::endl;
	std::cout << st.empty() << std::endl;
	st.pop();
	std::cout << st.empty() << std::endl;
	return 0;
}
