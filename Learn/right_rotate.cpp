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

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
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

int main() {
    Node* root = newNode(20);
    root->left = newNode(10);
    root->left->left = newNode(5);

    std::cout << "Before right rotation: ";
    preOrder(root);
    std::cout << std::endl;

    root = rightRotate(root);

    std::cout << "After right rotation: ";
    preOrder(root);
    std::cout << std::endl;

    return 0;
}
