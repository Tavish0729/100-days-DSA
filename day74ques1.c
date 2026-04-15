#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, count, maxVotes = 0;
    char names[100][50];
    char winner[50];

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    for(i = 0; i < n; i++) {
        count = 1;

        for(j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        if(count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}