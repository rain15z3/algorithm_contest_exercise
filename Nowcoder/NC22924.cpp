/* NC22924 货币系统
 * 来源: Nowcoder
 * 作者: RainbowBird
 * 日期: 2020-11-03
 * 算法: 完全背包
 */

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int v, n, a[26];
ll f[10005];

int main() {
    cin >> v >> n;
    for (int i = 1; i <= v; i++)
        cin >> a[i];

    f[0] = 1;
    for (int i = 1; i <= v; i++) {
        for (int j = a[i]; j <= n; j++) {
            f[j] += f[j-a[i]];
        }
    }

    cout << f[n] << endl;
    return 0;
}
