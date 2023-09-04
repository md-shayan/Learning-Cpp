#include <iostream>
#include <stack>
#include "Binary_Tree.h"

template <typename T>
void print_Tree(Binary_Tree<T> b_tree) {
	Node<T>* curr = b_tree.root;
	std::stack<Node<T>*> st;
	while (curr != nullptr) {
		std::cout << curr->data << std::endl;
		if (curr->right != nullptr) {st.push(curr->right);}
		if (curr->left != nullptr) {
			curr = curr->left;
		}
		else if (!st.empty()){
			curr = st.top();
			st.pop();
		}
		else {break;}
	}
}

int main() {
        Binary_Tree<int> b;
        b.set_root(15);

        b.left_Child(b.root, 17);
        b.right_Child(b.root, 20);

        b.left_Child(b.root->left, 22);
        b.right_Child(b.root->left, 13);

        b.left_Child(b.root->left->right, 12);
        b.right_Child(b.root->left->right, 28);

        b.left_Child(b.root->right, 25);
        b.right_Child(b.root->right->left, 33);
        b.left_Child(b.root->right->left->right, 14);
	print_Tree<int>(b);
        return 0;
}
