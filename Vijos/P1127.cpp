/* P1127 级数求和
 * 来源: NOIP2002
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 模拟
 */

#include <iostream>
using namespace std;

double S;
int n, k;

int main() {
    cin >> k;
    while (1) {
        S += 1.0 / ++n;
        if (S > k) break;
    }

    cout << n << endl;
    return 0;
}
