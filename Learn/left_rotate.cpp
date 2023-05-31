#include <iostream>
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

//recursively prints all the left then moves to the right
// so preOrder(root->left) moves the root key to the next left and on till it hits null
// then it breaks off that loop and prints the right
void preOrder(Node* root) {
    if (root != NULL) {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

int main() {

    Node* root = newNode(10);
    root->right = newNode(20);
    root->right->right = newNode(30);

    std::cout << "Before left rotation: ";
    preOrder(root);
    std::cout << std::endl;

    root = leftRotate(root);

    std::cout << "After left rotation: ";
    preOrder(root);
    std::cout << std::endl;

    return 0;
}
