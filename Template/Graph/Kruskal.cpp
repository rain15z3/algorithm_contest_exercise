/* Kruskal模板
 * 作者: RainbowBird
 * 日期: 2020-09-24
 */

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 10e5 + 5;

int n, m, ans, cnt;
int fa[MAXN];
struct Edge {
    int x, y, z;
} e[MAXN];

int getf(int x) {
    if (fa[x] == x) return x;
    return fa[x] = getf(fa[x]);
}

int merge(int x, int y) {
    int a = getf(x);
    int b = getf(y);
    if (a != b) {
        fa[b] = a;
        return true;
    }

    return false;
}

int cmp(Edge a, Edge b) {
    return a.z < b.z;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> e[i].x >> e[i].y >> e[i].z;
        fa[i] = i;
    }

    sort(e + 1, e + 1 + m, cmp);

    for (int i = 1; i <= m; i++) {
        if (cnt == n - 1) break;
        if (merge(e[i].x, e[i].y)) {
            ans += e[i].z;
            cnt++;
        }
    }

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (getf(i) == i) tot++;
    }

    if (tot > 1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}
