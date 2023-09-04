template <typename T>
struct Node {
	T data;
	Node<T> *parent, *left, *right;
	Node (T setData) : data{setData} {
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}
};

template <typename T>
class Binary_Tree {
	public:
		Node<T>* root;
		Binary_Tree() {root = nullptr;}
		
		void set_root(T elem) {root = new Node<T>(elem);}
		bool empty() {return root==nullptr;}

		void left_Child(Node<T>* parent, T elem) {
			Node<T>* newNode = new Node<T>(elem);
			if (empty()) {std::cout << "Parent Node Not Found" << std::endl;}
			else {
				newNode->parent = parent;
				parent->left = newNode;
			}
		}

		T data(Node<T>* parent) {return parent->data;}

		T left(Node<T>* parent) {return parent->left->data;}

		T right(Node<T>* parent) {return parent->right->data;}

		void right_Child(Node<T>* parent, T elem) {
			Node<T>* newNode = new Node<T>(elem);
			if (empty()) {std::cout << "Parent Node Not Found" << std::endl;}
			else {
				newNode->parent = parent;
				parent->right = newNode;
			}
		}
};
