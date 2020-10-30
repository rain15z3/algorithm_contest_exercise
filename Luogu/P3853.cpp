/* P3853 路标设置
 * 来源: TJOI 2007
 * 作者: RainbowBird
 * 日期: 2020-09-16
 * 算法: 二分答案
 */

#include <iostream>
using namespace std;

typedef long long ll;

ll len, n, k;
ll a[100005];

int check(int x) {
    int total = 0;
    ll last = a[1];

    for (int i = 2; i <= n; i++) {
        if (a[i] - last >= x) { // 如果中间需要插入一个路标
            total += (a[i] - last) / x;
            if ((a[i] - last) % x == 0) total--;
        }

        last = a[i];
    }

    return total <= k;
}

int main() {
    cin >> len >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll l = 0, r = len, mid;
    while (l < r) {
        mid = (l + r) / 2; // 最大距离
        if (check(mid)) r = mid; // 合格，减小mid获取最小值
        else l = mid + 1; // 不合格，增大mid来满足条件
    }

    cout << l << endl;
    return 0;
}
