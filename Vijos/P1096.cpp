/* P1096 津津的储蓄计划
 * 来源: NOIP2004
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 模拟
 */

#include <iostream>
using namespace std;

int money, mom;

int main() {
    for (int i = 1; i <= 12; i++) {
        money += 300;

        int cost;
        cin >> cost;
        
        if (money - cost >= 0) {
            money -= cost;
        } else {
            cout << "-" << i << endl;
            return 0;
        }

        if (money >= 100) {
            int give = money / 100 * 100;
            mom += give;
            money -= give;
        }
    }

    cout << mom * 1.2 + money << endl;
    return 0;
}
