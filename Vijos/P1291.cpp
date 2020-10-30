/* P1291 苹果摘淘淘
 * 来源: Vijos
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 贪心
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[2005], b[2005], used[2005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i]; // 苹果的高度
    for (int i = 1; i <= m; i++) cin >> b[i]; // 淘淘的高度
    
    // 排序
    sort(a + 1, a + n + 1, greater<int>());
    sort(b + 1, b + m + 1, greater<int>());

    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[j] == 0) continue; // 高度为0的淘淘不能摘
            if (a[i] > b[j] && used[j] == 0) {
                used[j] = 1;
                total++;
                break;
            }
        }
    }
    
    cout << m - total << endl;
    return 0;
}
