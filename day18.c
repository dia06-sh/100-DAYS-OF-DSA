#include <stdio.h>

int main() {
    int n, k, i, j;

    scanf("%d", &n);
    int arr[n];

    // Input array
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    // Rotate right k times
    for(i = 0; i < k; i++) {
        int last = arr[n - 1];   // store last element

        for(j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1]; // shift right
        }
