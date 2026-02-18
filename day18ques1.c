#include <stdio.h>

// Helper function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;

    // Input size
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input rotation steps
    if (scanf("%d", &k) != 1) return 1;

    // Handle cases where k > n
    k = k % n;
    
    if (k > 0) {
        // Step 1: Reverse the entire array
        reverse(arr, 0, n - 1);
        // Step 2: Reverse the first k elements
        reverse(arr, 0, k - 1);
        // Step 3: Reverse the rest
        reverse(arr, k, n - 1);
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}