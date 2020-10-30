/* P1082 同余方程
 * 来源: NOIP 2012
 * 作者: RainbowBird
 * 日期: 2020-10-26
 * 算法: exgcd
 */

#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll a, b, x, y;

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }

    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}

int main() {
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
    return 0;
}
