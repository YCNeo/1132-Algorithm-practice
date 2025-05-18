#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int x_left;
        int x_right;
} Wood;

/* 兩漂流木在 X 軸投影是否相交（端點亦算相交） */
static inline bool overlap(const Wood* a, const Wood* b) {
    return !(a->x_right <= b->x_left || b->x_right <= a->x_left);
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1)
        return 0;

    /* 讀取木頭區間 */
    Wood* river = malloc(sizeof(Wood) * N);
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &river[i].x_left, &river[i].x_right);

    /* BFS 配置──O(N) 記憶體 */
    int* dist = malloc(sizeof(int) * N);
    bool* visited = calloc(N, sizeof(bool));
    int* queue = malloc(sizeof(int) * N);
    int head = 0, tail = 0;

    for (int i = 0; i < N; ++i)
        dist[i] = INT_MAX;

    visited[0] = true;
    dist[0] = 0;
    queue[tail++] = 0; /* 起點入隊 */

    while (head < tail) {
        int u = queue[head++];

        if (u == N - 1) { /* 抵達終點，輸出最少跳數 */
            printf("%d\n", dist[u]);
            goto CLEANUP;
        }

        /* 動態檢查與 u 重疊的所有 v */
        for (int v = 0; v < N; ++v) {
            if (!visited[v] && overlap(&river[u], &river[v])) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                queue[tail++] = v;
            }
        }
    }

    /* 若題目保證必達，此行理論上不會輸出；保險起見放 -1 */
    printf("-1\n");

CLEANUP:
    free(queue);
    free(visited);
    free(dist);
    free(river);
    return 0;
}
