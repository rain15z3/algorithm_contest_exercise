/* P1113 不高兴的津津
 * 来源: NOIP2004
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 模拟
 */

#include <iostream>
using namespace std;

int main() {
    int maxn = 0, day = 0;
    for (int i = 1; i <= 7; i++) {
        int a, b;
        cin >> a >> b;
        if (a + b > 8 && a + b > maxn) {
            maxn = a + b;
            day = i;
        }
    }

    cout << day << endl;
    return 0;
}
