#include <stdio.h>

int main() {
    int p, q;
    
    // Read number of entries for server 1
    scanf("%d", &p);
    
    // Read server 1 log
    int log1[100000];  // Assuming max 100k entries
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    // Read number of entries for server 2
    scanf("%d", &q);
    
    // Read server 2 log
    int log2[100000];
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    // Merge the two sorted logs
    int i = 0, j = 0, k = 0;
    int result[200000];  // Combined max size
    
    // Compare and merge until one log is exhausted
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            result[k++] = log1[i++];
        } else {
            result[k++] = log2[j++];
        }
    }
    
    // Copy remaining elements from log1 (if any)
    while (i < p) {
        result[k++] = log1[i++];
    }
    
    // Copy remaining elements from log2 (if any)
    while (j < q) {
        result[k++] = log2[j++];
    }
    
    // Print the merged result
    for (int m = 0; m < k; m++) {
        printf("%d", result[m]);
        if (m < k - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
