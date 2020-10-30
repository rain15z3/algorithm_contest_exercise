/* UVA10474 大理石在哪儿
 * 作者：RainbowBird
 * 日期：2020-08-06
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m, step = 0;
    while (scanf("%d %d", &n, &m) == 2 && n) {
        printf("CASE# %d:\n", ++step);

        int a[10005];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        sort(a, a + n);

        for (int i = 0; i < m; i++) {
            int q;
            scanf("%d", &q);

            int *p = lower_bound(a, a + n, q);
            if (*p == q) printf("%d found at %d\n", q, int(p - a + 1));
            else printf("%d not found\n", q);
        }
    }

    return 0;
}
