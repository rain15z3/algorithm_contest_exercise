/* P2004 领地选择
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-09-21
 * 算法: 二维前缀和
 */

#include <iostream>
using namespace std;

int n, m, c;
int a[1005][1005];
int maxn = -0x7fffffff, x, y;

int main() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1]; // 求出二维前缀和
        }
    }

    for (int i = c; i <= n; i++) {
        for (int j = c; j <= m; j++) {
            int ans = a[i][j] - a[i - c][j] - a[i][j - c] + a[i - c][j - c];
            if (ans > maxn) {
                maxn = ans;
                x = i - c + 1;
                y = j - c + 1;
            }
        }
    }

    cout << x << " " << y << endl;
    return 0;
}
