/* P1103 校门外的树
 * 来源: NOIP 2005
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 模拟
 */

#include <iostream>
#include <cstring>
using namespace std;

int l, m, a[10005];

int main() {
    memset(a, 0, sizeof(a));
    cin >> l >> m;

    for (int i = 0; i <= l; i++) a[i] = 1;
    
    for (int i = 1; i <= m; i++) {
        int ta, tb;
        cin >> ta >> tb;
        for (int j = ta; j <= tb; j++) a[j] = 0;
    }

    int total = 0;
    for (int i = 0; i <= l; i++) {
        if (a[i] == 1) total++;
    }

    cout << total << endl;
    return 0;
}
