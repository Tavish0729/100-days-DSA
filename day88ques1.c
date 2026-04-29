#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if we can place k cows with at least 'mid' distance apart
int isPossible(int stalls[], int n, int k, int mid) {
    int count = 1; // Place the first cow in the first stall
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= mid) {
            count++;
            last_pos = stalls[i];
            if (count == k) return 1; // All cows placed successfully
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // 1. Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);

    // 2. Binary search on the possible distance
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(stalls, n, k, mid)) {
            ans = mid;     // This distance works, try for a larger one
            low = mid + 1;
        } else {
            high = mid - 1; // Too far apart, try a smaller distance
        }
    }

    printf("%d\n", ans);

    return 0;
}
