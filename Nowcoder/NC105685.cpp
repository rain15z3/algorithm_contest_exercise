/* NC105685 滑雪
 * 来源: 牛客
 * 作者: RainbowBird
 * 日期: 2020-09-06
 * 算法: 记忆化搜索
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[105][105], mem[105][105];
int nextn[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int x, int y) {
    if (mem[x][y] != 0) return mem[x][y];
    mem[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int tx = x + nextn[i][0];
        int ty = y + nextn[i][1];

        if (tx <= 0 || ty <= 0 || tx > n || ty > m) continue;

        if (a[tx][ty] < a[x][y]) {
            mem[x][y] = max(mem[x][y], dfs(tx, ty) + 1);
        }
    }

    return mem[x][y];
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans << endl;
    return 0;
}
