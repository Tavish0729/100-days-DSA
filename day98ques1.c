#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
struct Interval {
    int start;
    int end;
};

// Comparator function to sort intervals by their start time
int compareIntervals(const void* a, const void* b) {
    struct Interval* i1 = (struct Interval*)a;
    struct Interval* i2 = (struct Interval*)b;
    return i1->start - i2->start;
}

// Function to merge overlapping intervals
// Modifies the array in-place and returns the new size
int mergeIntervals(struct Interval arr[], int n) {
    if (n <= 0) return 0;

    // Step 1: Sort intervals based on start values
    qsort(arr, n, sizeof(struct Interval), compareIntervals);

    int index = 0; // Stores index of the last merged interval

    // Step 2: Traverse and merge intervals
    for (int i = 1; i < n; i++) {
        // If current interval overlaps with the last merged interval
        if (arr[index].end >= arr[i].start) {
            // Merge them by updating the end time
            if (arr[index].end < arr[i].end) {
                arr[index].end = arr[i].end;
            }
        } else {
            // Move to the next slot and copy the non-overlapping interval
            index++;
            arr[index] = arr[i];
        }
    }

    // Return the count of merged intervals (1-based index)
    return index + 1;
}

int main() {
    struct Interval arr[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original intervals:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
    printf("\n\n");

    int newSize = mergeIntervals(arr, n);

    printf("Merged intervals:\n");
    for (int i = 0; i < newSize; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
    printf("\n");

    return 0;
}
