/* P1525 关押罪犯
 * 来源: NOIP 2010
 * 作者: RainbowBird
 * 日期: 2020-10-28
 * 算法: 并查集
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int enemy[20005], f[20005];

struct Edge {
    int u, v, w;
} e[100005];

int cmp(Edge a, Edge b) {
    return a.w > b.w;
}

int getf(int x) {
    if (f[x] == x) return x;
    return f[x] = getf(f[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e + 1, e + 1 + m, cmp);
    
    for (int i = 1; i <= m; i++) {
        int x = getf(e[i].u);
        int y = getf(e[i].v);
        if (x == y) {
            cout << e[i].w << endl;
            return 0;
        }

        if (!enemy[e[i].u])
            enemy[e[i].u] = e[i].v;
        f[getf(enemy[e[i].u])] = f[getf(e[i].v)];

        if (!enemy[e[i].v])
            enemy[e[i].v] = e[i].u;
        f[getf(enemy[e[i].v])] = f[getf(e[i].u)];
    }

    cout << 0 << endl;
    return 0;
}
