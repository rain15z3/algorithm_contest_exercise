/* P5836 Milk Visits S
 * 来源: USACO
 * 作者: RainbowBird
 * 日期: 2020-09-15
 * 算法: 并查集
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

const int MAXN = 200005;
int n, m;
int fa[MAXN], ans[MAXN];
char col[MAXN];

int getf(int x) {
    if (fa[x] == x) return x;
    return fa[x] = getf(fa[x]);
}

void merge(int x, int y) {
    fa[getf(x)] = getf(y);
}

int main() {
    //freopen("P5836.in", "r", stdin);
    //freopen("P5836.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        cin >> col[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;

        if (col[u] == col[v]) merge(u, v);
    }

    int cur = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        char ask;
        cin >> u >> v >> ask;

        if (getf(u) == getf(v) && ask != col[u]) ans[++cur] = 0;
        else ans[++cur] = 1;
    }

    for (int i = 1; i <= cur; i++) {
        cout << ans[i];
    }

    cout << endl;
    return 0;
}

