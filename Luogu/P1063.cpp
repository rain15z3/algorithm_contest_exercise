/* P1063 能量项链
 * 来源: NOIP 2006
 * 作者: RainbowBird
 * 日期: 2020-10-23
 * 算法: 区间dp
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, f[105 * 2][105 * 2];

struct Node {
    int head, tail;
} a[105 * 2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        //cin >> a[i - 1].tail;
        //a[i].head = a[i - 1].tail;
        cin >> a[i].head;
        a[i-1].tail = a[i].head;
    }

    a[n].tail = a[1].head;
    for (int i = 1; i <= n; i++)
        a[i+n] = a[i];

    //a[1].head = a[0].tail;
    //a[n].tail = a[1].head;

    for (int x = 2; x <= n; x++) {
        for (int i = 1, j = x; j <= n * 2; i++, j++) {
            for (int k = i; k < j; k++) {
                f[i][j] = max(f[i][j], f[i][k] + f[k+1][j] + a[i].head * a[k].tail * a[j].tail);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i][i+n-1]);
    }

    cout << ans << endl;
    return 0;
}
