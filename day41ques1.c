#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the Queue structure to keep track of front and rear
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation: Add element to the end
void enqueue(struct Queue* q, int k) {
    struct Node* temp = newNode(k);
    
    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    // Add the new node at the end and update rear
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation: Remove element from the front
void dequeue(struct Queue* q) {
    // If queue is empty, print -1
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }
    
    // Store previous front and move front one node ahead
    struct Node* temp = q->front;
    printf("%d\n", temp->data);
    
    q->front = q->front->next;
    
    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Queue* q = createQueue();
    
    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);
        
        if (operation == 1) { // Assume 1 is for Enqueue
            int value;
            scanf("%d", &value);
            enqueue(q, value);
        } else if (operation == 2) { // Assume 2 is for Dequeue
            dequeue(q);
        }
    }
    
    return 0;
}
