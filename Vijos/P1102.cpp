/* P1102 陶陶摘苹果
 * 来源: NOIP2005
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 模拟
 */

#include <iostream>
using namespace std;

int a[10], l, total;

int main() {
    for (int i = 0; i < 10; i++) cin >> a[i];
    cin >> l;

    for (int i = 0; i < 10; i++) {
        if (l + 30 >= a[i]) total++;
    }

    cout << total << endl;
    return 0;
}
