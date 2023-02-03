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
 * @return struct Node* 
 */
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
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
 * @return struct Node* 
 */
struct Node *copyBinaryTreeRecursive(struct Node *root)
{
    if (root == NULL)
        return NULL;
    struct Node *newRoot = newNode(root->data);
    newRoot->left = copyBinaryTreeRecursive(root->left);
    newRoot->right = copyBinaryTreeRecursive(root->right);
    return newRoot;
}

/**
 * @brief Create a Queue object
 * 
 * @return struct Queue* 
 */
struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = 10;
    queue->front = queue->size = 0;
    queue->rear = queue->capacity - 1;
    queue->array = (struct Node**) malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

/**
 * @brief Add an item to the queue
 * 
 * @param queue
 * 
 * @return struct Node* 
 */
void enqueue(struct Queue* queue, struct Node* item)
{
    if (queue->size == queue->capacity) return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

/**
 * @brief Delete an item from queue
 * 
 * @return struct Node* 
 */
struct Node* dequeue(struct Queue* queue)
{
    if (isEmpty(queue)) return NULL;

    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

/**
 * @brief Check if the queue is empty
 * 
 * @param queue 
 * 
 * @return int 
 */
int isEmpty(struct Queue* queue)
{
    return queue->size == 0;
}

/**
 * 
 * @brief Copy a binary tree (non-recursively)
 * 
 * @param root
 * 
 * @return struct Node* 
 */
struct Node *copyBinaryTree(struct Node *root)
{
    if (root == NULL)
        return NULL;

    // Create a queue for level order traversal
    struct Queue *queue = createQueue();

    // Create a new root
    struct Node *newRoot = newNode(root->data);

    // Enqueue old and new root
    enqueue(queue, root);
    enqueue(queue, newRoot);

    // Do level order traversal of the tree
    while (!isEmpty(queue))
    {
        // Dequeue an old node and enqueue its children
        struct Node *old_node = dequeue(queue);
        struct Node *new_node = dequeue(queue);

        // Get the old and new node's children
        struct Node *oldLeft = old_node->left;
        struct Node *oldRight = old_node->right;

        // If the old node has a left child
        if (oldLeft)
        {
            // Create a new left child for the new node
            new_node->left = newNode(oldLeft->data);

            // Enqueue the left child
            enqueue(queue, oldLeft);
            enqueue(queue, new_node->left);
        }

        // If the old node has a right child
        if (oldRight)
        {
            // Create a new right child for the new node
            new_node->right = newNode(oldRight->data);

            // Enqueue the right child
            enqueue(queue, oldRight);
            enqueue(queue, new_node->right);
        }
    }

    return newRoot;
}

void printBinaryTree(struct Node *root)
{
    if (root == NULL) return;

    printf("%d ", root->data);

    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main(int argc, char** argv)
{
    // Create a binary tree
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    // Print the binary tree
    printf("Original binary tree: ");
    printBinaryTree(root);
    printf("\n");

    // Copy the binary tree
    struct Node *newRoot = copyBinaryTree(root);

    // Print the copied binary tree
    printf("Copied binary tree: ");
    printBinaryTree(newRoot);
    printf("\n");

    // Copy the binary tree with recursive algorithm
    struct Node *newRootRecursive = copyBinaryTreeRecursive(root);

    // Print the copied binary tree with recursive algorithm
    printf("Copied binary tree with recursive algorithm: ");
    printBinaryTree(newRootRecursive);
    printf("\n");

    return 0;
}
