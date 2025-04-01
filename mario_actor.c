#include <stdio.h>

int max_work_days(int jobs[][2], int n, int u, int v) {
    int max_days = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i][0] < u || jobs[i][1] > v)
            continue;
        int days = jobs[i][1] - jobs[i][0];


    }
    return max_days;
}

int main() {
    int n, u, v;
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

    printf("Jobs:\n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", jobs[i][0], jobs[i][1]);
    printf("available time: %d to %d\n", u, v);

    // printf("%d\n", max_work_days(jobs, n, u, v));

    return 0;
}