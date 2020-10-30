/* P1083 借教室
 * 来源: NOIP 2012
 * 作者: RainbowBird
 * 日期: 2020-10-25
 * 算法: 二分答案，前缀和
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10e6 + 5;
int n, m;
int r[MAXN], d[MAXN], s[MAXN], t[MAXN];
int num[MAXN], diff[MAXN];

int check(int x) { // x订单数量
    memset(diff, 0, sizeof(diff));
    memset(num, 0, sizeof(num));
    
    // 差分
    for (int i = 1; i <= x; i++) {
        diff[s[i]] += d[i];     // 起始日
        diff[t[i] + 1] -= d[i]; // 结束日
    }

    // 前缀和
    for (int i = 1; i <= n; i++) {
        //num[i] = r[i] + num[i-1]; // ri天能借的教室数量
        //if (num[i])
        num[i] = num[i-1] + diff[i];
        if (num[i] > r[i]) return false;
    }

    // 更新前缀和
    /*int op = 0;
    for (int i = 1; i <= x; i++) {
        op += diff[i];
        day[i] = num[i] + op;
        if (day[i] > num[i]) return false;
    }*/

    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= m; i++) cin >> d[i] >> s[i] >> t[i];

    if (check(m)) {
        cout << 0 << endl;
        return 0;
    }

    // 二分
    int l = 1, r = m, mid; // 二分订单数量
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }

    cout << -1 << endl;
    cout << l << endl;
    return 0;
}