#include <stdio.h>
#include <stdbool.h>

// Check if it's possible to paint all boards within 'limit' time using 'k' painters
bool isPossible(int boards[], int n, int k, long long limit) {
    int paintersCount = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + boards[i] <= limit) {
            currentSum += boards[i];
        } else {
            // Assign to a new painter
            paintersCount++;
            currentSum = boards[i];
            
            // If painters needed exceed available k, it's impossible
            if (paintersCount > k) return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low) low = boards[i]; // 'low' is the max single board
        high += boards[i];                   // 'high' is the total sum
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;   // Try to find a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;  // Need more time
        }
    }

    printf("%lld\n", result);

    return 0;
}
