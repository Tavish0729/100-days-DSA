#include <stdio.h>
#include <stdlib.h>

// Node for the linked list in each bucket
struct Node {
    float data;
    struct Node* next;
};

// Standard insertion sort to sort individual buckets
struct Node* insertionSort(struct Node* list) {
    if (!list || !list->next) return list;
    
    struct Node* sorted = NULL;
    struct Node* curr = list;
    
    while (curr) {
        struct Node* next = curr->next;
        if (!sorted || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
}

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    // 2. Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index based on float value
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    // 3. Sort each bucket and concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Clean up memory
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%.3f ", arr[i]);
    return 0;
}
