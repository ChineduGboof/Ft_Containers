In the context of a binary search tree, a successor node is the node that comes immediately after a given node in the sorted order of keys. It is the node with the smallest key value that is greater than the key of the given node. In other words, it is the next node you would encounter if you were traversing the tree in an ascending order of keys.

The function `getSuccessor` aims to find the successor node of a given node in a binary search tree. Here's how it works:

1. If the given node is the end node or is null, meaning it is the last node in the tree or does not exist, the function returns the end node (_end_node). This is typically a special sentinel node representing the end of the tree.

2. If the given node has a right child, the successor node is the leftmost (minimum) node in the right subtree. The function recursively calls `get_minimum_node` to find and return that node.

3. If the given node does not have a right child, the function uses a loop to search for the successor node in the ancestors of the given node. Starting from the root, it compares the key of the given node with the keys of the current root node and traverses left or right accordingly.

    - If the key of the given node is less than the key of the current root, it updates the successor node to the current root and moves to the left child of the root.

    - If the key of the given node is greater than the key of the current root, it moves to the right child of the root.

    - If the key of the given node is equal to the key of the current root, it means the current root is the given node itself. In this case, the loop breaks as the successor node is not found among the ancestors.

4. Finally, the function returns the successor node.

To better understand this process, let's consider a diagram of a binary search tree and random values:

```
         6
       /   \
      3     9
     / \   / \
    1   5 7   12
```

Suppose we want to find the successor of the node with the key 5. Here's how the function would work:

1. Start at the root node (key = 6).
2. Compare 5 with the key of the root (6).
3. Since 5 is less than 6, update the successor node to the current root (6) and move to the left child (3).
4. Compare 5 with the key of the current root (3).
5. Since 5 is greater than 3, move to the right child (5).
6. Compare 5 with the key of the current root (5).
7. Since 5 is equal to 5, the loop breaks, and the successor node remains as the previously updated value (6).
8. The function returns the successor node with the key 6.

In this case, the successor node of the node with the key 5 is the node with the key 6.

## Code

    node_pointer getSuccessor(node_pointer root, node_pointer node) {
        if (node == _end_node || !node) {
            return _end_node;
        } else if (node->right) {
            return get_minimum_node(node->right);
        }

        node_pointer successor = _end_node;
        while (root) {
            if (_key_comp(node->value.first, root->value.first)) {
                successor = root;
                root = root->left;
            } else if (_key_comp(root->value.first, node->value.first)) {
                root = root->right;
            } else {
                break;
            }
        }
        return successor;
    }