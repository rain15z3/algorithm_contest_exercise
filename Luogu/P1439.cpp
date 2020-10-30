/* P1439 【模板】最长公共子序列
 * https://www.luogu.com.cn/problem/P1439
 * 作者：RainbowBird
 * 日期：2020年7月7日
 * 算法：LCS
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int INF = 0x7fffffff;
int n, a[MAXN], b[MAXN], map[MAXN], f[MAXN], len;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        map[a[i]] = i; // 离散化
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        f[i] = INF;
    }

    // LIS
    for (int i = 1; i <= n; i++) {
        if (map[b[i]] > f[len]) {
            f[++len] = map[b[i]];
        } else {
            // lower_bound 找出第一个大于等于x的数
            // upper_bound 找出第一个大于x的数
            int *p = lower_bound(f + 1, f + 1 + len, map[b[i]]);
            *p = map[b[i]];

        }
    }

    cout << len << endl;
    return 0;
}
