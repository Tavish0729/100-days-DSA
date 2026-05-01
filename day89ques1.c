#include <stdio.h>
#include <stdbool.h>

/**
 * Helper function to determine if we can split the array into 'k' or fewer 
 * subarrays such that no subarray sum exceeds 'mid'.
 */
bool canSplit(int* nums, int numsSize, int k, long long mid) {
    int subarrayCount = 1;
    long long currentSum = 0;

    for (int i = 0; i < numsSize; i++) {
        // If a single element is larger than mid, this mid is impossible
        if (nums[i] > mid) return false;

        if (currentSum + nums[i] > mid) {
            // Start a new subarray
            subarrayCount++;
            currentSum = nums[i];
            // If we need more than k subarrays, mid is too small
            if (subarrayCount > k) return false;
        } else {
            currentSum += nums[i];
        }
    }
    return true;
}

int splitArray(int* nums, int numsSize, int k) {
    long long low = 0;
    long long high = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low) low = nums[i]; // Lower bound: Max element
        high += nums[i];                 // Upper bound: Sum of all elements
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            result = mid;    // Potential answer found, try to minimize further
            high = mid - 1;
        } else {
            low = mid + 1;   // mid is too small, increase the limit
        }
    }

    return (int)result;
}
