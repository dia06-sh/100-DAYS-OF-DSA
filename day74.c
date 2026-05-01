#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];
    int freq[n];
    
    // input votes
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
        freq[i] = 0;
    }

    // count frequency
    for(int i = 0; i < n; i++) {
        if(freq[i] == -1) continue;

        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
                freq[j] = -1; // mark visited
            }
        }
        freq[i] = count;
    }

    char winner[50];
    int maxVotes = 0;

    for(int i = 0; i < n; i++) {
        if(freq[i] == -1) continue;

        if(freq[i] > maxVotes) {
            maxVotes = freq[i];
            strcpy(winner, names[i]);
        }
        else if(freq[i] == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}