#include <stdio.h>
#include <limits.h>

int main() {
    static int brickColumns[2000000];
    int n = 0;

    // Read input
    while (scanf("%d", &brickColumns[n]) != EOF) {
        n++;
    }
    if (n == 0) {
        // no input => max sum is 0
        printf("0\n");
        return 0;
    }

    // Duplicate the array to handle wrap
    for (int i = 0; i < n; i++) {
        brickColumns[n + i] = brickColumns[i];
    }

    long long maxSum = 0;        // problem states we output 0 if negative
    long long currentSum = 0;
    int left = 0;  // left edge of the sliding window

    // Slide right edge i from 0 to 2n - 1
    for (int i = 0; i < 2 * n; i++) {
        currentSum += brickColumns[i];

        // If window size > n, drop the oldest from the sum
        if ((i - left + 1) > n) {
            currentSum -= brickColumns[left];
            left++;
        }

        // Track maxSum so far
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }

        // If sum goes negative, Kadane reset
        if (currentSum < 0) {
            currentSum = 0;
            left = i + 1;  // window restarts after i
        }
    }

    printf("%lld\n", maxSum);
    return 0;
}
