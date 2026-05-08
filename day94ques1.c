#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    // 1. Find the maximum element to determine the size of the frequency array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // 2. Build frequency array (count) and initialize with 0
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 3. Compute prefix sums (cumulative count)
    // This tells us the actual position of each element in the output array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build output array
    int *output = (int *)malloc(n * sizeof(int));
    // We iterate backwards to maintain stability (optional but good practice)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free allocated memory
    free(count);
    free(output);
}

// Helper function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    printArray(data, n);

    countingSort(data, n);

    printf("Sorted array:   ");
    printArray(data, n);

    return 0;
}
