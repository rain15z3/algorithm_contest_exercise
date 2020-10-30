/* P5020 货币系统
 * 来源: NOIP 2018
 * 作者: RainbowBird
 * 日期: 2020-10-15
 * 算法: 贪心
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
const int MAXN = 25005;
int n, a[105], b[MAXN], ans;

int main() {
    cin >> T;
    while (T--) {
        n = 0, ans = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[a[i]] = 2;
        }

        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= a[n]; i++) {
            if (b[i] > 0) {
                for (int j = 1; j <= n; j++) {
                    if (i + a[j] <= a[n]) {
                        b[i + a[j]] = 1;
                    } else {
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= a[n]; i++) {
            if (b[i] == 2)
                ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
