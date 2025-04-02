#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int start;
        int end;
        int duration;        // end - start
} Job;

// Comparison function to sort by end time ascending
int cmp(const void* a, const void* b) {
    Job* j1 = (Job*)a;
    Job* j2 = (Job*)b;
    if (j1->end != j2->end) {
        return j1->end - j2->end;
    } else {
        return j1->start - j2->start;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    Job allJobs[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &allJobs[i].start, &allJobs[i].end);
    }

    int u, v;
    scanf("%d %d", &u, &v);

    // 1) Filter: keep only intervals fully in [u, v].
    Job valid[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (allJobs[i].start >= u && allJobs[i].end <= v) {
            valid[count].start = allJobs[i].start;
            valid[count].end = allJobs[i].end;
            valid[count].duration = valid[count].end - valid[count].start;
            count++;
        }
    }
    // If none remain, answer is 0
    if (count == 0) {
        printf("0\n");
        return 0;
    }

    // 2) Sort by end time
    qsort(valid, count, sizeof(Job), cmp);

    // 3) Build array p[] in O(n) using a two-pointer technique
    int p[count];
    int j = -1;        // pointer to the "previous" job
    for (int i = 0; i < count; i++) {
        // Move j forward as far as possible where valid[j].end <=
        // valid[i].start
        while (j + 1 < i && valid[j + 1].end <= valid[i].start) {
            j++;
        }
        // Now j is the largest index < i with end <= start[i], or -1 if none
        p[i] = (j >= 0 && valid[j].end <= valid[i].start) ? j : -1;
    }

    // 4) DP to find max total duration
    //    dp[i] = max total duration using intervals up to index i
    int dp[count];
    dp[0] = valid[0].duration;        // best we can do with only the first job

    for (int i = 1; i < count; i++) {
        // Option1: skip interval i
        int skip = dp[i - 1];

        // Option2: take interval i
        int take = valid[i].duration;
        if (p[i] != -1) {
            take += dp[p[i]];
        }

        // dp[i] = best of skipping or taking
        dp[i] = (skip > take) ? skip : take;
    }

    // The answer is dp[count - 1]
    printf("%d\n", dp[count - 1]);
    return 0;
}
