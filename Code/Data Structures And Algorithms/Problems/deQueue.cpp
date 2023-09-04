#include <iostream>

enum Direction {
	Front,
	Back,
};

template <typename T>
class Dequeue {
	int* queue;
	int front_index, back_index;
	public:
		const int maxSize;
		Dequeue(int max_Size) : maxSize{max_Size} {
			queue = new T[maxSize];
			front_index = maxSize/2;
			back_index = maxSize/2;
		}
		
		void enQueue(T elem, Direction direction) {
			if (front_index == back_index) {
				queue[front_index] = elem;
				front_index++;
				back_index--;
				return;
			}
			switch(direction) {
				case Front:
					queue[front_index] = elem;
					front_index++;
					break;	
				case Back:
					queue[back_index] = elem;
					back_index--;
					break;
			}
		}

		bool empty() {return front_index == back_index;}

		int get_front() {return front_index;}
		int get_back() {return back_index+1;}

		void deQueue(Direction direction) {
			if (front_index == back_index) {
				queue[back_index] = 0;
				front_index--;
				back_index++;
				return;
			}
			switch(direction) {
				case Front:
					queue[front_index-1] = 0;
					front_index--;
					break;
				case Back:
					queue[back_index+1] = 0;
					back_index++;
					break;
			}
		}

		T* data() {return queue;}
};

void printdeQueue(int* arr, int start, int end) {
	std::cout << "{";
	for (int i=start; i<end; i++) {std::cout << " " << arr[i];}
	std::cout << " }" << std::endl;
}

int main() {
	Dequeue<int> dq(5);
	printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	dq.enQueue(3, Back);
	printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	dq.enQueue(2, Front);
	printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	dq.enQueue(4, Back);
	printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	dq.enQueue(1, Front);
       	printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	dq.enQueue(5, Back);
        printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	dq.deQueue(Front);
        printdeQueue(dq.data(), dq.get_back(), dq.get_front()); 
	dq.deQueue(Back);
	printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	dq.deQueue(Front);
        printdeQueue(dq.data(), dq.get_back(), dq.get_front());
        dq.deQueue(Back);
        printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	dq.deQueue(Front);
        printdeQueue(dq.data(), dq.get_back(), dq.get_front());
	return 0;
}
