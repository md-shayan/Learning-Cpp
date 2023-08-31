// Implement two stacks into a single array A in such a way that neither of the two stacks overflow or undernflow unless
// The total number of elements in both the stacks is equal to A.size.
// The Push and Pop operations should run in O(1) time at max.
#include <iostream>

enum Direction {
	Forward,
	Backward,
};

// A Backward Stack pushes and pops an element at the back of Array arr.
// While a Forward Stack pushes and pops an element at the forward of Array arr.
struct Stack {
	int* arr;
	int size = 0;
	int maxSize;
	const Direction direction;
	Stack(int* A, int maxSize, Direction d) : direction{d} {
		arr = A;
		this->maxSize = maxSize;
	}
};

void Push(Stack* S, int elem) {
	switch (S->direction) {
		case Direction::Forward:
			S->arr[S->size] = elem;
			S->size++;
			break;
		case Direction::Backward:
			S->arr[S->maxSize - S->size - 1] = elem;
			S->size++;
			break;
	}
}

void Pop(Stack* S) {
	switch (S->direction) {
		case Direction::Forward:
			S->arr[S->size-1] = 0;
			S->size--;
			break;
		case Direction::Backward:
			S->arr[S->maxSize - S->size - 1] = 0;
			S->size--;
			break;
	}
}

void printArray(int* arr, int size) {
	for (int i=0; i<size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int maxSize{5};
	int* arr = new int[maxSize];
	Stack Sf(arr, maxSize, Forward); // The Forward Stack.
	Stack Sb(arr, maxSize, Backward); // The Backward Stack.
	printArray(arr, maxSize);
	Push(&Sf, 1); // {1, 0, 0, 0, 0}
	Push(&Sb, 5); // {1, 0, 0, 0, 5}
	printArray(arr, maxSize);
	Push(&Sf, 2); // {1, 2, 0, 0, 5}
	Push(&Sb, 4); // {1, 2, 0, 4, 5}
	printArray(arr, maxSize);
	Push(&Sf, 3); // Same as Push(&Sb, 3); {1, 2, 3, 4, 5}
	Pop(&Sf); // {1, 2, 0, 4, 5}
	printArray(arr, maxSize);
	return 0;
}