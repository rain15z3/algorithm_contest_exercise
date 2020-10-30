/* P1006 传纸条
 * https://www.luogu.com.cn/problem/P1006
 * 作者：RainbowBird
 * 日期：2020年7月10日
 * 算法：动态规划
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[55][55], f[55][55][55][55];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            f[i][j][i][j] = a[i][j];
        }
    }

    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = 1; x2 <= n; x2++) {
                for (int y2 = 1; y2 <= m; y2++) {
                    f[x1][y1][x2][y2] = max(f[x1 - 1][y1][x2 - 1][y2],
                        max(f[x1][y1 - 1][x2][y2 - 1],
                        max(f[x1 - 1][y1][x2][y2 - 1],
                        f[x1][y1 - 1][x2 - 1][y2]))) + a[x1][y1] + a[x2][y2];

                    if (x1 == x2 && y1 == y2)
                        f[x1][y1][x2][y2] -= a[x1][y1];
                }
            }
        }
    }

    cout << f[n][m-1][n-1][m] << endl;

    return 0;
}
