/* LCS - 最长公共子序列
 * 复杂度：O(n^2)
 * 作者：RainbowBird
 * 日期：2020年7月5日
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int n, a[MAXN], b[MAXN], f[MAXN][MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    cout << f[n][n] << endl;
    return 0;
}
