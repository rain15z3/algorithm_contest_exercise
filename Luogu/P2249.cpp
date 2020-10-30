/* P2249 【深基13.例1】查找
 * https://www.luogu.com.cn/problem/P2249
 * 作者：RainbowBird
 * 日期：2020年7月9日
 * 算法：二分查找
 */

#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int n, m;
ll a[1000005];

int qread() {
    int k = 0, base = 1;
    char temp;
    temp = getchar();
    while (temp < '0' || temp > '9') {
        if (temp == '-')
            base = -1;
        temp = getchar();
    }

    while (temp >= '0' && temp <= '9') {
        k = k * 10 + (temp - '0');
        temp = getchar();
    }

    return k * base;
}


int main() {
    n = qread();
    m = qread();

    for (int i = 1; i <= n; i++)
        a[i] = qread();
    
    for (int i = 1; i <= m; i++) {
        int x = qread();

        int l = 1, r = n, mid, flag = false;
        while (l <= r) {
            mid = (l + r) / 2;
            //printf("[%d-%d] %lld\n", l, r, a[mid]);

            if (a[mid] >= x)
                r = mid;
            else
                l = mid + 1;

            //printf("[%d-%d] %lld\n", l, r, a[mid]);

            if (l == r) {
                if (a[l] == x) {
                    flag = true;
                    printf("%d ", l);
                }

                break;
            }
        }

        if (!flag)
            printf("-1 ");
    }


    return 0;
}

