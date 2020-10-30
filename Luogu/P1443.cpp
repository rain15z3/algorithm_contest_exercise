/* P1443 马的遍历
 * https://www.luogu.com.cn/problem/P1443
 * 作者：RainbowBird
 * 日期：2020年7月14日
 * 算法：BFS
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n, m, startx, starty, a[405][405];
int nextn[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

struct node {
    int x, y, step;
};

int main() {
    cin >> n >> m >> startx >> starty;
    memset(a, -1, sizeof(a));

    // 初始化队列
    queue<node> que;
    node head = {startx, starty, 0};
    que.push(head);
    a[startx][starty] = 0;

    while (!que.empty()) {
        node cur = que.front();

        // 寻路
        for (int k = 0; k < 8; k++) {
            int tx = cur.x + nextn[k][0];
            int ty = cur.y + nextn[k][1];

            // 边界判断
            if (tx < 1 || ty < 1 || tx > n || ty > m)
                continue;

            if (a[tx][ty] != -1)
                continue;
            
            a[tx][ty] = cur.step + 1;
            node push = {tx, ty, cur.step + 1};

            //printf("[%d %d] %d\n", tx, ty, cur.step + 1);

            que.push(push);
        }

        que.pop();
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
