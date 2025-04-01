#include <stdio.h>
#include <time.h>

int maxSubStrSum(int arr[], int len) {
    int max = 0, curValue;
    for (int i = 0; i < len; i++) {
        int j = i + 1;
        curValue = 0;
        // j point to index 0
        if (i == len - 1)
            j = 0;

        while (1) {
            curValue += arr[j++];
            if (curValue > max)
                max = curValue;

            // breakdown validation
            if (j == i + 1)
                break;
            if (j == len)
                j = 0;
        }
    }

    if (max < 0)
        return 0;
    return max;
}

int main() {
    clock_t start = clock();
    int brickColumns[1000000];
    int count = 0;

    // input and basic validation
    while (scanf("%d", &brickColumns[count++]) != EOF) {
        if (count == 1000000) {
            printf("Too many inputs\n");
            break;
        }
        if (brickColumns[count - 1] > 100 || brickColumns[count - 1] < -100) {
            printf("Invalid input\n");
            break;
        }
    }

    printf("%d\n", maxSubStrSum(brickColumns, count));

    printf("Used time = %ld\n", clock() - start);
    return 0;
}