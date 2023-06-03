In the context of a binary search tree, a predecessor node is the node that comes immediately before a given node in the sorted order of keys. It is the node with the largest key value that is smaller than the key of the given node. In other words, it is the previous node you would encounter if you were traversing the tree in an ascending order of keys.

The function `getPredecessor` aims to find the predecessor node of a given node in a binary search tree. Here's how it works:

1. If the given node is null, meaning it does not exist, the function returns the end node (_end_node). This is typically a special sentinel node representing the end of the tree.

2. If the given node is the end node (_end_node), meaning it is the last node in the tree, the function calls `get_maximum_node` to find and return the maximum (rightmost) node in the entire tree.

3. If the given node has a left child, the predecessor node is the rightmost (maximum) node in the left subtree of the given node. The function recursively calls `get_maximum_node` to find and return that node.

4. If the given node does not have a left child, the function uses a loop to search for the predecessor node in the ancestors of the given node. Starting from the root, it compares the key of the given node with the keys of the current root node and traverses left or right accordingly.

    - If the key of the given node is greater than the key of the current root, it updates the predecessor node to the current root and moves to the right child of the root.

    - If the key of the given node is less than the key of the current root, it moves to the left child of the root.

    - If the key of the given node is equal to the key of the current root, it means the current root is the given node itself. In this case, the loop breaks as the predecessor node is not found among the ancestors.

5. Finally, the function returns the predecessor node.

In the given binary search tree:

```
         6
       /   \
      3     9
     / \   / \
    1   5 7   12
```

If we want to find the predecessor of the node with the key 9, the correct process would be as follows:

1. Start at the root node (key = 6).
2. Compare 9 with the key of the root (6).
3. Since 9 is greater than 6, move to the right child (key = 9).
4. The right child (key = 9) has a left subtree, so we move to the left child of the right child (key = 7).
5. The left child (key = 7) does not have any further left children, so it becomes the predecessor of the node with the key 9.

Therefore, in this case, the predecessor node of the node with the key 9 is the node with the key 7.


## Code

    node_pointer getPredecessor(node_pointer root, node_pointer node) {
        if (!node) {
            return _end_node;
        } else if (node == _end_node) {
            return get_maximum_node(root);
        } else if (node->left) {
            return get_maximum_node(node->left);
        }

        node_pointer predecessor = _end_node;
        while (root) {
            if (_key_comp(root->value.first, node->value.first)) {
                predecessor = root;
                root = root->right;
            } else if (_key_comp(node->value.first, root->value.first)) {
                root = root->left;
            } else {
                break;
            }
        }
        return predecessor;
    }