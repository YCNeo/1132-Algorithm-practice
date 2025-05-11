#include <stdio.h>

// int dfs(int n, int m, int a[n][m], int b[n][m], int i, int j) {
//     if (i < 0 || i >= n || j < 0 || j >= m) {
//         return 0;
//     }
//     if (a[i][j] == 1) {
//         return 0;
//     }
//     if (b[i][j] == 1) {
//         return 0;
//     }
//     b[i][j] = 1;
//     return 1 + dfs(n, m, a, b, i - 1, j) + dfs(n, m, a, b, i + 1, j) +
//            dfs(n, m, a, b, i, j - 1) + dfs(n, m, a, b, i, j + 1);
// }

int main() {
    int n, table[1000][1000] = {}, visited[1000][1000] = {};
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int u = 0, j = 1;
        scanf("%d", &u);
        table[u - 1][0] = u;
        while (scanf("%d", &table[u - 1][j++]) != EOF) {
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}