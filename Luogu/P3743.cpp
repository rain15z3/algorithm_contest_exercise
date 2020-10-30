/* P3743 kotori的设备
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-09-16
 * 算法: 贪心，二分答案
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, p;

struct Node {
    double a, b;
} machine[100005];
 
int check(double x) {
    double total = 0;
    for (int i = 1; i <= n; i++) {
        double used = x * machine[i].a;
        if (machine[i].b - used <= 0) { // 需要充电宝充电
            total += used - machine[i].b; // 记录需要的能量
        }
    }

    return total <= (p * x);
}

int main() {
    cin >> n >> p;

    double total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> machine[i].a >> machine[i].b;
        total += machine[i].a;
    }

    if (total <= p) {
        cout << -1.000000 << endl;
        return 0;
    }

    double l = 0, r = 1e10, mid;
    while (r - l > 1e-6) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << endl;
    return 0;
}
