/* P1802 五倍经验日
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-09-15
 * 算法: 动态规划
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, x;
ll lose[1005], win[1005], use[1005];
ll f[1005][1005];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> lose[i] >> win[i] >> use[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j >= use[i]) {
                f[i][j] = max(f[i - 1][j] + lose[i], f[i - 1][j - use[i]] + win[i]);
            } else {
                f[i][j] = f[i - 1][j] + lose[i];
            }
        }
    }

    cout << f[n][x] * 5 << endl;
    return 0;
}
