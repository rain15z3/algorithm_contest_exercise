/* P2440 木材加工
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-09-16
 * 算法: 二分答案
 */

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, k;
ll a[100005];

int check(ll x) {
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x) {
            total += a[i] / x;
        }
    }

    if (total >= k) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n >> k;

    ll len = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        len = max(len, a[i]);
    }

    ll l = 0, r = len, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << endl;
    return 0;
}
