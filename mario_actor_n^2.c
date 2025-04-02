#include <stdio.h>

#define MAX 1000        // Adjust as necessary for maximum rows

int n, u, v, max_days = 0;

int count_days(int routine[][2], int m) {
    int count = 0;
    for (int i = 0; i < m; i++)
        if (routine[i][0] >= u && routine[i][1] <= v)
            count += routine[i][1] - routine[i][0];

    return count;
}

// validate if the routine[] is valid
int is_valid(int routine[][2], int m) {
    for (int i = 0; i < m; i++) {
        if (routine[i][0] < u || routine[i][1] > v)
            return 0;
        if (i != m - 1)
            if (routine[i][1] > routine[i + 1][0])
                return 0;
    }
    return 1;
}

// A helper function to print a combination of size m
void printCombination(int combo[][2], int m) {
    printf("[");
    for (int i = 0; i < m; i++) {
        // Print each pair
        printf("[%d, %d]", combo[i][0], combo[i][1]);
        if (i < m - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/*
    Recursive utility function:
    arr:   the original array of pairs
    n:     how many pairs are in arr
    m:     the combination size to pick
    start: the next index in arr from which we pick a pair
    combo: temporary array to hold the current combination
    index: how many pairs have currently been chosen in combo
*/
void combinationUtil(int arr[][2],
                     int n,
                     int m,
                     int start,
                     int combo[][2],
                     int index) {
    // If we have chosen m pairs, print the combo
    if (index == m) {
        // printCombination(combo, m);
        if (is_valid(combo, m)) {
            // printf("Valid.\n");
            int days = count_days(combo, m);
            if (days > max_days)
                max_days = days;

            // printf("Max days: %d\n", max_days);
        }
        return;
    }

    // If we've run out of pairs to pick from, just return
    if (start >= n) {
        return;
    }

    // For each possible choice of the next pair
    for (int i = start; i < n; i++) {
        // Include arr[i] in the current combination
        combo[index][0] = arr[i][0];
        combo[index][1] = arr[i][1];

        // Recurse to choose the remaining pairs
        combinationUtil(arr, n, m, i + 1, combo, index + 1);
    }
}

void combination(int arr[][2], int n, int m) {
    int combo[MAX][2];
    combinationUtil(arr, n, m, 0, combo, 0);
}

int main(void) {
    scanf("%d", &n);
    int jobs[n][2];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &jobs[i][0], &jobs[i][1]);
    scanf("%d %d", &u, &v);

    // sort jobs by their start time and end time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j][0] > jobs[j + 1][0]) {
                int temp[2];
                temp[0] = jobs[j][0];
                temp[1] = jobs[j][1];
                jobs[j][0] = jobs[j + 1][0];
                jobs[j][1] = jobs[j + 1][1];
                jobs[j + 1][0] = temp[0];
                jobs[j + 1][1] = temp[1];
            } else if (jobs[j][0] == jobs[j + 1][0]) {
                if (jobs[j][1] > jobs[j + 1][1]) {
                    int temp[2];
                    temp[0] = jobs[j][0];
                    temp[1] = jobs[j][1];
                    jobs[j][0] = jobs[j + 1][0];
                    jobs[j][1] = jobs[j + 1][1];
                    jobs[j + 1][0] = temp[0];
                    jobs[j + 1][1] = temp[1];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        // printf("Combination of size %d:\n", i);
        combination(jobs, n, i);
    }

    printf("%d\n", max_days);

    return 0;
}
