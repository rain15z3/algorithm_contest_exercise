/* P1217 乒乓球
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 模拟
 */

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, game[25 * 2500 + 5];

int main() {
    // 读入数据
    memset(game, 0, sizeof(game));
    char ch = getchar();
    while (ch != 'E') {
        if (ch == 'W') game[++n] = 1;
        else if (ch == 'L') game[++n] = 2;
        ch = getchar();
    }

    if (n == 0) n = 1;

    // 11分制
    {
        int k = 1;
        while (k <= n + 1) {
            // 进行一轮比赛
            int a = 0, b = 0, i = 1;
            while (k <= n + 1) {
                if ((a >= 11 || b >= 11) && abs(a-b) >= 2) break;

                if (game[k] == 1) a++;
                else if (game[k] == 2) b++;

                k++, i++;
            }

            // 结束这一轮比赛
            printf("%d:%d\n", a, b);
        }
    }

    printf("\n");

    // 21分制
    {
        int k = 1;
        while (k <= n + 1) {
            // 进行一轮比赛
            int a = 0, b = 0, i = 1;
            while (k <= n + 1) {
                if ((a >= 21 || b >= 21) && abs(a-b) >= 2) break;

                if (game[k] == 1) a++;
                else if (game[k] == 2) b++;

                k++, i++;
            }

            // 结束这一轮比赛
            printf("%d:%d\n", a, b);
        }
    }

    return 0;
}
