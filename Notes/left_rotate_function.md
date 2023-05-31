#   Map - AVL Tree Left Rotate Function

## Breakdown

Let's go through the left rotation step by step using the example of nodes with keys 10, 20, and 30.

Initially, the tree structure looks like this:
```
    10
      \
       20
         \
          30
```

1. Perform the left rotation:
   - Node `x` is the root node with key 10.
   - Node `y` is `x`'s right child with key 20.
   - Node `T2` is the left child of `y`, which is null.
   
2. Perform the rotation:
   - Assign `y->left` as `x` to make `x` the left child of `y`.
   - Assign `x->right` as `T2` to make `T2` the right child of `x`.
   
   After the rotation, the tree becomes:
```
    20
   /  \
  10   30
```

3. Update the heights:
   - Update the height of node `x` by taking the maximum height between its left and right children (`height(10) = 0` and `height(30) = 0`), and adding 1. So `x->height` becomes 1.
   - Update the height of node `y` by taking the maximum height between its left and right children (`height(10) = 0` and `height(30) = 0`), and adding 1. So `y->height` becomes 1.

After the left rotation, the tree is transformed into a balanced structure:
```
    20
   /  \
  10   30
```

When you run the provided code, it will output:
```
Before left rotation: 10 20 30
After left rotation: 20 10 30
```

This demonstrates how the left rotation operation rearranges the numbers 10, 20, and 30 to achieve a balanced tree structure.

## Code

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
