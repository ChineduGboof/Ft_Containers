Sure! Let's consider a binary search tree diagram and some random values to explain these functions:

```
         8
       /   \
      3     10
     / \      \
    1   6      14
       / \    /
      4   7  13
```

1. `get_minimum_node(node_pointer node)`: This function returns the node with the minimum key value in a given subtree rooted at `node`. Starting from the given `node`, it iteratively traverses down the left child pointers until it reaches the leftmost node, which will have the minimum key value.

   Let's say we call `get_minimum_node` with `node` pointing to the root node (key = 8). The function would traverse down the left child pointers until it reaches the leftmost node, which is the node with the key 1. Hence, it returns the pointer to this node.

2. `get_maximum_node(node_pointer node)`: This function returns the node with the maximum key value in a given subtree rooted at `node`. Starting from the given `node`, it iteratively traverses down the right child pointers until it reaches the rightmost node, which will have the maximum key value.

   Let's say we call `get_maximum_node` with `node` pointing to the root node (key = 8). The function would traverse down the right child pointers until it reaches the rightmost node, which is the node with the key 14. Hence, it returns the pointer to this node.

These functions are useful when you need to find the minimum or maximum value in a binary search tree or a subtree. By repeatedly following the appropriate child pointers, you can efficiently find the desired node with the minimum or maximum key value.

## Code

   node_pointer get_minimum_node(node_pointer node) {
      node_pointer min_node = node;
      while (min_node->left) {
         min_node = min_node->left;
      }
      return min_node;
   }

   node_pointer get_maximum_node(node_pointer node) {
      node_pointer max_node = node;
      while (max_node->right) {
         max_node = max_node->right;
      }
      return max_node;
   }