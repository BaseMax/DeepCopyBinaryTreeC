#include <strio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/**
 * @brief Create a new node object
 * 
 * @param data
 * 
 * @return struct node* 
 */
struct node *newNode(int data);

/**
 * @brief Copy a binary tree (recursively)
 * 
 * @param root
 * 
 * @return struct node* 
 */
struct node *copyBinaryTreeRecursive(struct node *root);

/**
 * @brief Copy a binary tree (non-recursively)
 * 
 * @param root
 * 
 * @return struct node* 
 */
struct node *copyBinaryTree(struct node *root);
