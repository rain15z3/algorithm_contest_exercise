/* P1776 宝物筛选
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-10-30
 * 算法: 多重背包
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int v, w;
} item[105];

int n, W, tot;
int f[40005];

int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        int v, w, m;
        cin >> v, w, m;
        for (int j = 1; j <= m; j++) {
            item[++tot].v = v;
            item[tot].w = w;
        }
    }

    n = tot;

    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= 1; j--) {
            f[j] = max(f[j], f[j-item[i].w] + item[i].v);
        }
    }

    cout << f[1] << endl;
    return 0;
}
