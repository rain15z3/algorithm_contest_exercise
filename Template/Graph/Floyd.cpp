/* Floyd模板
 * 作者: RainbowBird
 * 日期: 2020-09-26
 */

#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x7ffffff;
int n, m, e[105][105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) e[i][j] = 1;
            e[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u][v] = w;
        e[v][u] = w;
    }

    // Floyd
    for (int k = 1; k <= n; k++) { // 中间点
        for (int i = 1; i <= n; i++) { // 起点
            for (int j = 1; j <= n; j++) { // 终点
                if ((e[i][k] != INF) && (e[k][j] != INF) && (e[i][k] + e[k][j] < e[i][j])) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }

    return 0;
}
