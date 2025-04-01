#include <limits.h>
#include <stdio.h>

long long kadaneMax(const int arr[], int n) {
    long long maxEndingHere = 0, maxSoFar = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        maxEndingHere += arr[i];
        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
        }
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
    return maxSoFar;
}

// Return max subarray sum in circular array
long long maxCircularSubarray(int arr[], int n) {
    // 1) Normal Kadane’s
    long long maxNormal = kadaneMax(arr, n);

    // Check if all negative => problem wants 0 if so
    if (maxNormal <= 0) {
        return 0;
    }

    // 2) Sum of the entire array
    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // 3) Kadane’s to find the minimum subarray (by inverting signs)
    for (int i = 0; i < n; i++) {
        arr[i] = -arr[i];        // invert
    }
    long long maxInverted = kadaneMax(arr, n);
    long long minSubarray = -maxInverted;

    // 4) wrapSum
    long long wrapSum = totalSum - minSubarray;

    // 5) Answer is max of normal or wrap
    long long ans = (wrapSum > maxNormal) ? wrapSum : maxNormal;
    return (ans > 0) ? ans : 0;        // ensure >= 0
}

int main() {
    static int arr[2000000];
    int n = 0;
    while (scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    // If no input
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    long long ans = maxCircularSubarray(arr, n);
    printf("%lld\n", ans);
    return 0;
}
