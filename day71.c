#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hashTable[1000];
int m = 7;  // table size (can be changed)

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (hashTable[index] == EMPTY || hashTable[index] == key) {
            hashTable[index] = key;
            return;
        }
    }
}

int search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (hashTable[index] == EMPTY)
            return 0;

        if (hashTable[index] == key)
            return 1;
    }
    return 0;
}

int main() {
    for (int i = 0; i < m; i++)
        hashTable[i] = EMPTY;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}