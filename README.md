# DeepCopyBinaryTreeC

A C program to deep copy a binary tree. Deep copy means that any changes made to the new binary tree don't affect the original binary tree. Both recursive and iterative algorithms are implemented. The iterative algorithm a few lines of code and uses a variable to keep track of the current node. The recursive algorithm is a bit more complicated but it's easier to understand.

### Tree and Binary-tree

A Tree is a data structure that consists of nodes in a parent/child relationship. A Binary Tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.

## Compile

```bash
$ gcc DeepCopyBinaryTree.c -o DeepCopyBinaryTree
$ ./DeepCopyBinaryTree
```

## Example

```c
// Create a binary tree
struct node *root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = newNode(6);

// Copy the binary tree
struct node *newRoot = copyBinaryTree(root);

// Print the binary tree
printf("Original binary tree: ");
printBinaryTree(root);

// Print the copied binary tree
printf("Copied binary tree: ");
printBinaryTree(newRoot);

// Copy the binary tree with recursive algorithm
struct node *newRootRecursive = copyBinaryTreeRecursive(root);

// Print the copied binary tree with recursive algorithm
printf("Copied binary tree with recursive algorithm: ");
printBinaryTree(newRootRecursive);
```

Copyright (c) 2023, Max Base
