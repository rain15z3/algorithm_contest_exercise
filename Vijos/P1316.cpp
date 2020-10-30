/* P1316 明明的随机数
 * 来源: NOIP2006
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: STL, 排序
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, a[105], maxn, total;

int main() {
    memset(a, 0, sizeof(a));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int na;
        cin >> na;
        a[na] = 1;
        maxn = max(na, maxn);
    }

    for (int i = 0; i <= maxn; i++) {
        if (a[i] == 1) total++;
    }

    cout << total << endl;
    for (int i = 0; i <= maxn; i++) {
        if (a[i] == 1)
            cout << i << " ";
    }
    
    return 0;
}
