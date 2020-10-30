/* P1848 选数问题
 * 来源: Vijos
 * 作者: RainbowBird
 * 日期: 2020-08-20
 * 算法: NONE
 */

#include <iostream>
using namespace std;

int total;

void findn(int x, int n) {
    while (x > 0) {
        int temp = x % 10;
        x /= 10;
        if (temp == n) total++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        findn(i, m);
    }

    cout << total << endl;
    return 0;
}
