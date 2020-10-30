/* P5019 铺设道路
 * 来源: NOIP 2018
 * 作者: RainbowBird
 * 日期: 2020-10-15
 * 算法: 贪心
 */

#include <iostream>
using namespace std;

int n, a[100005], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            ans += a[i] - a[i - 1];
        }
    }

    cout << ans + a[1] << endl;
    return 0;
}
