/**
 * 
 * @file DeepCopyBinaryTree.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief C Implementation of deep copy algorithm to copy a binary-tree object
 * @version 0.1
 * @date 2023-02-03
 * @copyright Copyright (c) 2023
 * 
 */

#include "DeepCopyBinaryTree.h"

/**
 * @brief Create a new node object
 * 
 * @param data
 * 
 * @return struct node* 
 */
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

/**
 * @brief Copy a binary tree (recursively)
 * 
 * @param root
 * 
 * @return struct node* 
 */
struct node *copyBinaryTreeRecursive(struct node *root)
{
    if (root == NULL)
        return NULL;
    struct node *newRoot = newNode(root->data);
    newRoot->left = copyBinaryTreeRecursive(root->left);
    newRoot->right = copyBinaryTreeRecursive(root->right);
    return newRoot;
}

/**
 * @brief Copy a binary tree (non-recursively)
 * 
 * @param root
 * 
 * @return struct node* 
 */
struct node *copyBinaryTree(struct node *root)
{
    if (root == NULL)
        return NULL;
    struct node *newRoot = newNode(root->data);
    struct node *current = root;
    struct node *newCurrent = newRoot;
    struct node *parent = NULL;
    struct node *newParent = NULL;
    while (current != NULL)
    {
        if (current->left != NULL)
        {
            newCurrent->left = newNode(current->left->data);
            parent = current;
            current = current->left;
            newParent = newCurrent;
            newCurrent = newCurrent->left;
        }
        else if (current->right != NULL)
        {
            newCurrent->right = newNode(current->right->data);
            parent = current;
            current = current->right;
            newParent = newCurrent;
            newCurrent = newCurrent->right;
        }
        else
        {
            current = parent;
            newCurrent = newParent;
            parent = NULL;
            newParent = NULL;
        }
    }
    return newRoot;
}

void printBinaryTree(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main(int argc, char** argv)
{
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

    return 0;
}
