/* P1020 导弹拦截
 * https://www.luogu.com.cn/problem/P1020
 * 作者：RainbowBird
 * 日期：2020年7月7日
 * 算法：LIS
 */

#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 100000 + 5;
const int INF = 0x7fffffff;

int n, a[MAXN];
int f1[MAXN];   // 最长上升子序列
int f2[MAXN];   // 最长不升子序列

int main() {
    while (cin >> a[++n]);
    n--;

    // 初始化
    for (int i = 1; i <= n; i++)
        f1[i] = INF, f2[i] = INF;
    int len1 = 1, len2 = 1;
    f1[1] = a[1], f2[1] = a[1];

    // 最长上升子序列
    for (int i = 2; i <= n; i++) {
        if (f1[len1] < a[i]) {
            // 下一个数比它大的话就添加到后面去
            f1[++len1] = a[i];
        } else {
            // 找不到就考虑用一个更小的数替换掉这个数
            int *p = lower_bound(f1 + 1, f1 + len1 + 1, a[i]);
            *p = a[i];
        }
    }

    // 最长不上升子序列
    for (int i = 2; i <= n; i++) {
        if (f2[len2] >= a[i]) {
            f2[++len2] = a[i];
        } else {
            int *p = upper_bound(f2 + 1, f2 + len2 + 1, a[i], greater<int>());
            *p = a[i];
        }
    }

    cout << len2 << endl;
    cout << len1 << endl;
    return 0;
}
