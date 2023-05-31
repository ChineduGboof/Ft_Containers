#   The Insert Function (AVL Tree- Map)

## Breakdown

The `insert` function is used to insert a new node with a given key into a binary search tree (BST). I'll explain the steps involved using simple numbers and pictures.

Let's consider an example where we have a BST initially with nodes having keys 10, 20, and 30:

```
      20
     /  \
    10   30
```

Now, we want to insert a new node with key 15 into the BST using the `insert` function.

1. Start by comparing the key of the new node (15) with the key of the current node (20). Since 15 is less than 20, we move to the left subtree.

```
      20
     /  \
    10   30
   /
  15
```

2. Now, we check if the left child of the current node exists. If it does, we recursively call the `insert` function on the left subtree with the new node.

```
      20
     /  \
    10   30
   /
  15
```

3. Repeat the comparison and insertion process until we find a suitable position for the new node. In this case, we insert the new node with key 15 as the left child of the node with key 10.

```
      20
     /  \
    10   30
   /  \
  15
```

4. After inserting the new node, we need to update the height of the ancestor nodes. Starting from the newly inserted node, we go up the tree, updating the height of each ancestor node by taking the maximum height between its left and right subtrees and adding 1.

```
      20
     /  \
    10   30
   /  \
  15
```

5. Next, we check the balance factor of the ancestor node. If the balance factor indicates that the tree has become unbalanced, we need to perform rotations to restore the balance.

6. In the given code, there are four cases for unbalanced nodes:
   - Left Left Case: If the balance factor is greater than 1 and the key to be inserted is less than the key of the left child of the unbalanced node, perform a right rotation.
   - Right Right Case: If the balance factor is less than -1 and the key to be inserted is greater than the key of the right child of the unbalanced node, perform a left rotation.
   - Left Right Case: If the balance factor is greater than 1 and the key to be inserted is greater than the key of the left child of the unbalanced node, perform a left rotation on the left child and then a right rotation on the unbalanced node.
   - Right Left Case: If the balance factor is less than -1 and the key to be inserted is less than the key of the right child of the unbalanced node, perform a right rotation on the right child and then a left rotation on the unbalanced node.

7. After performing the necessary rotations, the tree is rebalanced, and the insertion process is complete.

In the given example, since we inserted the key 15 into the BST, there were no unbalanced nodes, so no rotations were performed.

Please note that this explanation assumes a basic understanding of binary search trees and rotations. The actual process may involve more complex tree structures and multiple rotations in certain cases.

## CODE

    #include <iostream>

    // An AVL tree node
    class Node
    {
    public:
        int key;
        Node *left;
        Node *right;
        int height;
    };

    // A utility function to get the
    // height of the tree
    int height(Node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }

    // A utility function to get maximum
    // of two integers
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    /* Helper function that allocates a
    new node with the given key and
    NULL left and right pointers. */
    Node* newNode(int key)
    {
        Node* node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1; // new node is initially
                        // added at leaf
        return(node);
    }

    // A utility function to right
    // rotate subtree rooted with y
    // See the diagram given above.
    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left),
                        height(y->right)) + 1;
        x->height = max(height(x->left),
                        height(x->right)) + 1;

        // Return new root
        return x;
    }

    // A utility function to left rotate subtree rooted with x
    // See the diagram given above.
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

    // Get Balance factor of node N
    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    // Recursive function to insert a key
    // in the subtree rooted with node and
    // returns the new root of the subtree.
    Node* insert(Node* node, int key)
    {
        /* 1. Perform the normal BST insertion */
        if (node == NULL)
            return(newNode(key));

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // Equal keys are not allowed in BST
            return node;

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height(node->left),
                            height(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    // A utility function to print preorder
    // traversal of the tree.
    // The function also prints height
    // of every node
    void preOrder(Node* root)
    {
        if (root != NULL)
        {
            std::cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    // Driver Code
    int main()
    {
        Node* root = NULL;

        /* Constructing tree given in
        the above figure */
        root = insert(root, 10);
        root = insert(root, 20);
        root = insert(root, 30);
        root = insert(root, 40);
        root = insert(root, 50);
        root = insert(root, 25);

        /* The constructed AVL Tree would be
                30
                / \
                20 40
                / \ \
            10 25 50
        */
        std::cout << "Preorder traversal of the "
                "constructed AVL tree is \n";
        preOrder(root);

        return 0;
    }

