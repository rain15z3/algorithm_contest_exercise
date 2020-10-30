/* P1064 金明的预算方案
 * 来源: NOIP 2006
 * 作者: RainbowBird
 * 日期: 2020-10-25
 * 算法: 01背包
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 4 * 10e4 + 5;
int n, m;
int item_c[MAXN], item_v[MAXN];
int annex_c[MAXN][3], annex_v[MAXN][3];
int f[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int cost, value, id;
        cin >> cost >> value >> id;
        if (!id) {
            item_c[i] = cost;
            item_v[i] = value * cost;
        } else {
            annex_c[id][0]++;
            annex_c[id][annex_c[id][0]] = cost;
            annex_v[id][annex_c[id][0]] = value * cost;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 0; j--) {
            if (item_c[i] != 0 && item_c[i] <= j) {
                f[j] = max(f[j], f[j - item_c[i]] + item_v[i]);
                if (item_c[i] + annex_c[i][1] <= j)
                    f[j] = max(f[j], f[j - item_c[i] - annex_c[i][1]] + item_v[i] + annex_v[i][1]);
                if (item_c[i] + annex_c[i][2] <= j)
                    f[j] = max(f[j], f[j - item_c[i] - annex_c[i][2]] + item_v[i] + annex_v[i][2]);
                if (item_c[i] + annex_c[i][1] + annex_c[i][2] <= j)
                    f[j] = max(f[j], f[j - item_c[i] - annex_c[i][1] - annex_c[i][2]] + item_v[i] + annex_v[i][1] + annex_v[i][2]);
            }
        }
    }

    cout << f[n] << endl;
    return 0;
}
