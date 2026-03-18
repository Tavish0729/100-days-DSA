#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue structure
struct Queue {
    int front, rear;
    int size;
    struct Node** array;
};

// Create queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->array = (struct Node**)malloc(size * sizeof(struct Node*));
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1) return;

    if (q->front == -1)
        q->front = 0;

    q->array[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;

    struct Node* temp = q->array[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue(100);

    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(q, temp->left);

        if (temp->right != NULL)
            enqueue(q, temp->right);
    }
}

// Main function
int main() {
    // Example tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}