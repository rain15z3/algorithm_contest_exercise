/* NC14709 奇妙拆分
 * 来源: Nowcoder
 * 作者: RainbowBird
 * 日期: 2020-11-02
 * 算法: 枚举
 */

#include <iostream>
using namespace std;

int T, n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;

        int tot = 0;
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0) n /= i, tot++;
        }

        cout << tot + 1 << endl;
    }

    return 0;
}
