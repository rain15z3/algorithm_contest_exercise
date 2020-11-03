/* NC21228 货币系统
 * 来源: Nowcoder
 * 作者: RainbowBird
 * 日期: 2020-11-03
 * 算法: 筛法
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int T;
// 核心思想：判断某个数能不能被之前的数给凑出来

int main() {
    cin >> T;
    while (T--) {
        int n, a[105], money[25005]; // 0 1 2
        cin >> n;
        memset(money, 0, sizeof(money));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            money[a[i]] = 2; // 就是自己
        }

        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= a[n]; i++) {
            if (money[i] > 0) { // 如果money[i]能被凑出来
                // 则 money[i + a[j]] 也能凑出来
                for (int j = 1; j <= n; j++) {
                    if (i + a[j] > a[n]) break; // 防止数组越界
                    money[i + a[j]] = 1;
                }
            }
        }

        int tot = 0; // 不能被别的货币凑到的数额即最小的个数
        for (int i = 1; i <= a[n]; i++) {
            if (money[i] == 2) tot++;
        }

        cout << tot << endl;
    }
    return 0;
}
