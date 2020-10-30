/* P1280 尼克的任务
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-09-29
 * 算法: dp
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, num = 1, f[10005], sum[10005];

struct Node {
    int s, t;
} a[10005];

int cmp(Node a, Node b) {
    return a.s > b.s;
}

int main() {
    cin >> n >> k;
    memset(f, 0, sizeof(f));
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));

    for (int i = 1; i <= k; i++) {
        cin >> a[i].s >> a[i].t;
        sum[a[i].s]++;
    }
    
    sort(a + 1, a + 1 + k, cmp);

    for (int i = n; i >= 1; i--) {
        if (sum[i] == 0) { // 当前时刻空闲
            f[i] = f[i + 1] + 1;
        } else {
            for (int j = 1; j <= sum[i]; j++) {
                if (f[i + a[num].t] > f[i])
                    f[i] = f[i + a[num].t];
                num++;
            }
        }
    }

    cout << f[1] << endl;
    return 0;
}
