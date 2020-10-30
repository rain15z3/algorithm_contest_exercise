/* 快速幂模板
 * 日期: 2020-08-30
 */

#include <iostream>
using namespace std;

// a ^ b % p
int quick_pow(int a, int b, int p) {
    int t = a; // 倍增（a^1 a^2 a^3 ...）
    int ans = 1;
    while (b > 0) {
        if (b & 1) // 二进制最后一位是1
            ans = (ans * t) % p;
        t = (t * t) % p;
        b >>= 1; // 计算下一个二进制的值
    }
    return ans;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << quick_pow(a, b, p) << endl;
    return 0;
}
