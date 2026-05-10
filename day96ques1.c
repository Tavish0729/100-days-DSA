#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays and counts cross-inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be filled in temp array
    long long inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // All remaining elements in left subarray are greater than arr[j]
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Auxiliary function that uses merge sort to count inversions
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in left division
        inv_count += mergeSortAndCount(arr, temp, left, mid);

        // Count inversions in right division
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        // Count split inversions during merge
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

// Wrapper function
long long getInversionCount(int arr[], int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    long long ans = mergeSortAndCount(arr, temp, 0, n - 1);
    free(temp);
    return ans;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    long long inversions = getInversionCount(arr, n);
    printf("Number of inversions are: %lld\n", inversions);
    
    return 0;
}
