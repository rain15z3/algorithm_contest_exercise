/* P1144 最短路计数
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-10-29
 * 算法: Dijkstra
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

int n, m;
int dis[1000005], ans[1000005], vis[1000005];
//priority_queue<int, vector<int>, greater<int> > que; // 小根堆
priority_queue<pair<int, int> > que;

namespace Edge {
    int head[2000005 * 2], tot = 0;

    struct Edge {
        int u, v, next;
    } e[2000005 * 2];

    void init() {
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v) {
        e[++tot].u = u;
        e[tot].v = v;
        e[tot].next = head[u];
        head[u] = tot;
    }
}

int main() {
    freopen("P1144.in", "r", stdin);
    Edge::init();
    cin >> n >> m;
    memset(dis, 127, sizeof(dis));

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        Edge::addEdge(u, v);
        Edge::addEdge(v, u);
    }

    // Dijkstra
    que.push(make_pair(0, 1));
    dis[1] = 0;
    ans[1] = 1;
    while (!que.empty()) {
        int x = que.top().second;
        que.pop();

        if (vis[x]) break;
        vis[x] = 1;

        for (int i = Edge::head[x]; i; i = Edge::e[i].next) {
            int v = Edge::e[i].v;
            if (dis[v] > dis[x] + 1) {
                dis[v] = dis[x] + 1;
                ans[v] = ans[x];
                que.push(make_pair(-dis[v], v));
            } else if (dis[v] == dis[x] + 1) {
                ans[v] += ans[x];
                ans[v] %= 100003;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}
