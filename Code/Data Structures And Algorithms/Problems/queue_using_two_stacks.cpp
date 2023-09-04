#include <iostream>
#include <stack>

template <typename T>
class Queue {
	public:
	std::stack<T> queue;
	std::stack<T> temp;

	void enQueue(T elem) {queue.push(elem);}

	void deQueue() {
		while (!queue.empty()) {
			temp.push(queue.top());
			queue.pop();
		}
		temp.pop();
		while (!temp.empty()) {
			queue.push(temp.top());
			temp.pop();
		}
	}

};

int main() {
	Queue<int> q;
	q.enQueue(1);
	q.queue.empty() ? std::cout << " " : std::cout << q.queue.top();
	std::cout << std::endl;
	q.deQueue();
	q.queue.empty() ? std::cout << " " : std::cout << q.queue.top();
	std::cout << std::endl;
	return 0;
}
