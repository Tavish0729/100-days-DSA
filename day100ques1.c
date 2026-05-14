#include <stdio.h>
#include <stdlib.h>

// Structure to pair array values with their original indices
typedef struct {
    int value;
    int index;
} Element;

// Merge function to combine two sorted halves and count inversions
void merge(Element arr[], int left, int mid, int right, int count[]) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    // Allocate temporary arrays for merging
    Element* L = (Element*)malloc(left_size * sizeof(Element));
    Element* R = (Element*)malloc(right_size * sizeof(Element));

    for (int i = 0; i < left_size; i++) L[i] = arr[left + i];
    for (int j = 0; j < right_size; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int right_count = 0; // Tracks elements taken from the right subarray

    // Merge process
    while (i < left_size && j < right_size) {
        if (L[i].value <= R[j].value) {
            // Element from left is smaller or equal
            // Any elements already taken from right are smaller than L[i]
            count[L[i].index] += right_count;
            arr[k++] = L[i++];
        } else {
            // Element from right is strictly smaller
            right_count++;
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i < left_size) {
        count[L[i].index] += right_count;
        arr[k++] = L[i++];
    }

    // Copy remaining elements from right subarray
    while (j < right_size) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

// Recursive function to perform merge sort
void mergeSort(Element arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

// Main driving function
int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Element* arr = (Element*)malloc(n * sizeof(Element));
    int* count = (int*)calloc(n, sizeof(int));

    // Initialize elements with their values and original positions
    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    // Execute the counting sort logic
    mergeSort(arr, 0, n - 1, count);

    // Display output results
    printf("Original Array: ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    
    printf("\nInversion Counts: ");
    for (int i = 0; i < n; i++) printf("%d ", count[i]);
    printf("\n");

    free(arr);
    free(count);
    return 0;
}
