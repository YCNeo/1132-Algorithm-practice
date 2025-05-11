#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000    /* 1 ≤ N ≤ 1000 */
#define MAXLINE 6000 /* 單行最長字元數 (足夠 1001 個整數) */

/* -------- Union–Find -------- */
int parent[MAXN + 1], rnk[MAXN + 1];

int find(int x) {
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (rnk[a] < rnk[b])
        parent[a] = b;
    else if (rnk[a] > rnk[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rnk[a]++;
    }
}
/* ---------------------------------- */

char adj[MAXN + 1][MAXN + 1]; /* 去重複用：1 MB */

int main(void) {
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    getchar(); /* 吃掉換行 */

    for (int i = 1; i <= N; ++i) { /* 初始化並查集 */
        parent[i] = i;
        rnk[i] = 0;
    }
    memset(adj, 0, sizeof(adj));

    int redundant = 0; /* 有無多餘邊旗標 */
    char line[MAXLINE];

    for (int row = 0; row < N && fgets(line, sizeof(line), stdin);) {
        /* 可能有空白行，跳過不計入 row */
        if (line[0] == '\n' || line[0] == '\r')
            continue;
        ++row;

        /* 逐行讀取：第 1 個數是城市 u，後面每個 v 表示邊 (u,v) */
        int nums[1002], cnt = 0;
        for (char* tok = strtok(line, " \t\r\n"); tok;
             tok = strtok(NULL, " \t\r\n"))
            nums[cnt++] = atoi(tok);

        if (cnt == 0)
            continue; /* 不應發生 */

        int u = nums[0];
        for (int k = 1; k < cnt; ++k) {
            int v = nums[k];
            if (u < 1 || u > N || v < 1 || v > N)
                continue; /* 保險檢查 */

            if (adj[u][v])
                continue; /* 已處理過這條邊 */
            adj[u][v] = adj[v][u] = 1;

            /* cycle 檢測 & 合併 */
            if (find(u) == find(v))
                redundant = 1; /* 形成環 -> 有多餘邊 */
            else
                unite(u, v);
        }
    }

    /* 統計連通分量個數 */
    int seen[MAXN + 1] = {0}, components = 0;
    for (int i = 1; i <= N; ++i) {
        int r = find(i);
        if (!seen[r]) {
            seen[r] = 1;
            ++components;
        }
    }

    int P = components - 1; /* 至少需新增的邊數 */
    int Q = redundant;      /* 是否有多餘邊 */

    printf("%d %d\n", P, Q);
    return 0;
}
