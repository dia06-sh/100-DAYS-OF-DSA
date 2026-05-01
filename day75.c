#include <stdio.h>

int maxZeroSumSubarray(int arr[], int n) {
    int prefixSum = 0, maxLen = 0;

    // Using simple arrays as hashmap substitute
    int map[100000] = {0};  // stores first index
    for (int i = 0; i < 100000; i++) map[i] = -2;

    int offset = 50000; // to handle negative sums

    map[offset] = -1; // prefix sum 0 at index -1

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (map[prefixSum + offset] != -2) {
            int len = i - map[prefixSum + offset];
            if (len > maxLen) maxLen = len;
        } else {
            map[prefixSum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxZeroSumSubarray(arr, n));
    return 0;
}