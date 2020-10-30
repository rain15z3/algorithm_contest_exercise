/* P1135 奇怪的电梯
 * 来源: 洛谷
 * 作者: RainbowBird
 * 日期: 2020-09-20
 * 算法: 搜索
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, k[205];
int ans = 0x3f3f3f;
int book[205];

void dfs(int x, int total) {
    if (x == b) {
        ans = min(ans, total);
        return;
    }

    if (x > n || x < 1 || total > n) return;


    if (total < ans) { // 剪枝优化
        book[x] = 1;
        if (x + k[x] <= n && book[x + k[x]] != 1) dfs(x + k[x], total + 1);
        if (x - k[x] >= 1 && book[x - k[x]] != 1) dfs(x - k[x], total + 1);
        book[x] = 0;
        
    }
}

int main() {
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) cin >> k[i];

    dfs(a, 0);

    cout << ((ans == 0x3f3f3f) ? -1 : ans) << endl;
    return 0;
}
