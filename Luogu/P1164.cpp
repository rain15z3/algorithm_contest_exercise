/* P1164 小A点菜
 * 作者: RainbowBird
 * 日期: 2020-08-14
 * 算法: DP
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, a[105];
int f[105][10005];

// f[i][j] => 前i道菜花费的j元办法总数

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {          // 第i道菜
        for (int j = 1; j <= m; j++) {      // 剩余j元
            if (a[i] == j) {                // 如果钱刚好够买这道菜
                f[i][j] = f[i-1][j] + 1;    // 上一道菜的方法数加一
            } else if (a[i] < j) {          // 如果可以买这道菜还有多余的钱
                f[i][j] = f[i-1][j] + f[i-1][j-a[i]]; // 方法数是吃这道菜的总数和不吃这道菜的总数之和
            } else if (a[i] > j) {          // 如果钱不够
                f[i][j] = f[i-1][j];        // 方法数等于上一道的方法数
            }
        }
    }

    printf("%d\n", f[n][m]);
    return 0;
}
