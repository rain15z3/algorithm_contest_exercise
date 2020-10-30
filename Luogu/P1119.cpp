/* P1119 灾后重建
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-09-28
 * 算法: Floyd
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, q, a[205], e[205][205], book[205];

int qread() {
    int k = 0, base = 1;
    char ch = getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-') base = -1;
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        k = k * 10 + (ch - '0');
        ch = getchar();
    }

    return k * base;
}

void floyd(int k, int u, int v) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (e[i][j] > e[i][k] + e[k][j]) {
                e[i][j] = e[j][i] = e[i][k] + e[k][j];

                //if ((i == u && j == v) || (j == u && i == v)) return;
            }
        }
    }
}

int main() {
    memset(a, 0, sizeof(a));
    memset(e, 0, sizeof(book));
    memset(book, 0, sizeof(book));

    n = qread(), m = qread();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) e[i][j] = 0;
            e[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        a[i] = qread();
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        u = qread(), v = qread(), w = qread();
        u++, v++;
        e[u][v] = w;
        e[v][u] = w;
    }

    q = qread();
    for (int i = 1; i <= q; i++) {
        int u, v, t;
        u = qread(), v = qread(), t = qread();
        u++, v++;

        int k = 1;
        for (; a[k] <= t && k <= n; k++) {
            if (book[k]) continue;
            book[k] = 1;

            floyd(k, u, v);
        }

        if ((a[u] > t || a[v] > t) || (e[u][v] == INF)) {
            printf("-1\n");
        } else {
            printf("%d\n", e[u][v]);
        }
    }

    return 0;
}
