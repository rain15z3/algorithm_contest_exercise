/* P1873 砍树
 * https://www.luogu.com.cn/problem/P1873
 * 作者：RainbowBird
 * 日期：2020年7月10日
 * 算法：二分答案
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, m, a[1000000 + 5], l, r, mid;

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        r = max(a[i], r); // 找出最高的树
    }

    // 二分答案
    while (l <= r) {
        mid = (l + r) / 2; // 伐木机高度

        ll temp = 0;

        // 检查答案
        for (int i = 1; i <= n; i++) {
            if (a[i] > mid) {
                temp += a[i] - mid;
            }
        }

        if (temp < m) {
            r = mid - 1; // 减小高度增加木材
        } else {
            l = mid + 1; // 寻找最优答案
        }
    }

    printf("%lld\n", r);
    return 0;
}
