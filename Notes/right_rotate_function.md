#   Map - AVL Tree Right Rotate Function

## Breakdown

Let's go step by step through the right rotation function using the example: `20, 10, 5`. We'll visualize the tree structure before and after the rotation.

1. Initial Tree:
```
    20
   /
  10
 /
5
```

2. Before Right Rotation:
   - `y` is the root node with key `20`.
   - `x` is the left child of `y` with key `10`.
   - `T2` is the right child of `x`, which is `NULL`.

3. Perform Right Rotation:
   - `x` is rotated to become the new root node, and `y` becomes its right child.
   - `T2` is assigned as the left child of `y`.
   - Heights are updated for both `y` and `x`.

```
    10
   /  \
  5    20
```

4. After Right Rotation:
```
    10
   /  \
  5    20
```

The numbers `20`, `10`, and `5` were rearranged through the right rotation operation, resulting in a balanced tree structure.

Note: The `preOrder` function is used to print the keys of the nodes in the tree before and after the rotation. In this example, it will output:
```
Before right rotation: 20 10 5 
After right rotation: 10 5 20 
```

## Code

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
    
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
