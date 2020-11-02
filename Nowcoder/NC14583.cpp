/* NC14583 糖糖别胡说，我真的不是签到题目
 * 来源: Nowcoder
 * 作者: RainbowBird
 * 日期: 2020-11-02
 * 算法: 前缀和
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Tang {
    int a, b;
} tang[500005];

int T, n, m;
int c[500005];

int main() {
    cin >> T;
    while (T--) {
        memset(tang, 0, sizeof(tang));
        memset(c, 0, sizeof(c));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> tang[i].a >> tang[i].b;
        for (int j = 1; j <= m; j++) {
            int a;
            cin >> a;
            c[a]++;
        }

        // 求出第n秒所有人的战力
        for (int i = n; i >= 1; i--) {
            c[i] += c[i+1];
            tang[i].b += c[i];
        }

        int cnt = 0, max1 = 0, max2 = 0;
        for (int i = n; i >= 1; i--) {
            if (tang[i].a == 0) {
                max1 = max(max1, tang[i].b);
                if (max2 >= tang[i].b) cnt++;
            } else if (tang[i].a == 1) {
                max2 = max(max2, tang[i].b);
                if (max1 >= tang[i].b) cnt++;
            }
        }

        cout << n - cnt << endl;
    }

    return 0;
}