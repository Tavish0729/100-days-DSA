#include <stdio.h>
#include <stdlib.h>

// Structure to represent a meeting interval
typedef struct {
    int start;
    int end;
} Interval;

// Min-Heap structure to track room end times
typedef struct {
    int* data;
    int size;
} MinHeap;

// Swap helper function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain heap property upwards after insertion
void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->data[idx] < heap->data[parent]) {
            swap(&heap->data[idx], &heap->data[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

// Maintain heap property downwards after removal
void heapifyDown(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;
    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap->data[idx], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert an end time into the min-heap
void push(MinHeap* heap, int val) {
    heap->data[heap->size] = val;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Remove the earliest end time from the min-heap
void pop(MinHeap* heap) {
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
}

// Return the earliest end time
int top(MinHeap* heap) {
    return heap->data[0];
}

// Comparator function to sort intervals by start time
int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Core function to find minimum meeting rooms required
int minMeetingRooms(Interval* intervals, int intervalsSize) {
    if (intervalsSize <= 0) return 0;

    // 1. Sort intervals by start time
    qsort(intervals, intervalsSize, sizeof(Interval), compareIntervals);

    // 2. Initialize the min-heap
    MinHeap heap;
    heap.data = (int*)malloc(intervalsSize * sizeof(int));
    heap.size = 0;

    // Allocate the first meeting to a room
    push(&heap, intervals[0].end);

    // 3. Process remaining meetings
    for (int i = 1; i < intervalsSize; i++) {
        // If the room with the earliest end time is free, reuse it
        if (intervals[i].start >= top(&heap)) {
            pop(&heap);
        }
        // Allocate current meeting's end time to the heap
        push(&heap, intervals[i].end);
    }

    int totalRooms = heap.size;
    free(heap.data);
    return totalRooms;
}

int main() {
    Interval intervals[] = {{0, 30}, {5, 10}, {15, 20}};
    int size = sizeof(intervals) / sizeof(intervals[0]);

    int rooms = minMeetingRooms(intervals, size);
    printf("Minimum meeting rooms required: %d\n", rooms);

    return 0;
}
