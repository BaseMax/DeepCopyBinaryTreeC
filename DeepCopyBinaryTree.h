#include <stdio.h>
#include <stdlib.h>

/**
 * @brief A node of a binary tree
 */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/**
 * @brief A queue of nodes
 */
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    struct Node **array;
};

/**
 * @brief Create a Queue object
 * 
 * @return struct Queue* 
 */
struct Queue* createQueue();

/**
 * @brief Add an item to the queue
 * 
 * @param queue
 * 
 * @return struct Node* 
 */
void enqueue(struct Queue* queue, struct Node* item);

/**
 * @brief Delete an item from queue
 * 
 * @return struct Node* 
 */
struct Node* dequeue(struct Queue* queue);

/**
 * @brief Check if the queue is empty
 * 
 * @param queue 
 * 
 * @return int 
 */
int isEmpty(struct Queue* queue);

/**
 * @brief Create a new node object
 * 
 * @param data
 * 
 * @return struct Node* 
 */
struct Node *newNode(int data);

/**
 * @brief Copy a binary tree (recursively)
 * 
 * @param root
 * 
 * @return struct Node* 
 */
struct Node *copyBinaryTreeRecursive(struct Node *root);

/**
 * @brief Copy a binary tree (non-recursively)
 * 
 * @param root
 * 
 * @return struct Node* 
 */
struct Node *copyBinaryTree(struct Node *root);
