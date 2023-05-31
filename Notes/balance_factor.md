#   Balance Factor

## Breakdown

The `getBalance` function calculates the balance factor of a given node `N`. The balance factor is determined by subtracting the height of the right subtree from the height of the left subtree. 

To explain it using simple numbers and pictures, let's consider an example with nodes having keys 10, 20, 30, and 40:

```
      20
     /  \
    10   30
            \
             40
```

In this example, we want to calculate the balance factor of node 20. 

1. Calculate the height of the left subtree of node 20:
   - The left subtree of node 20 consists of node 10.
   - The height of node 10 is 1.
   
2. Calculate the height of the right subtree of node 20:
   - The right subtree of node 20 consists of nodes 30 and 40.
   - The height of node 30 is 1.
   - The height of node 40 is 0.
   - Therefore, the height of the right subtree is 1 (maximum height among nodes 30 and 40).

3. Calculate the balance factor of node 20:
   - Subtract the height of the right subtree (1) from the height of the left subtree (1).
   - The balance factor of node 20 is 0.

The balance factor indicates whether a node is balanced, left-heavy, or right-heavy. 
- If the balance factor is 0, it means the left and right subtrees have the same height, and the node is balanced.
- If the balance factor is positive, it means the left subtree is taller than the right subtree, and the node is left-heavy.
- If the balance factor is negative, it means the right subtree is taller than the left subtree, and the node is right-heavy.

In the example above, since the balance factor of node 20 is 0, it is balanced.

In code, the `getBalance` function would return the balance factor of the given node.

## Code

    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
