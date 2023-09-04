#include <iostream>
#include "Binary_Tree.h"

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
	return 0;
}
