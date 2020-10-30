/* Bellman-Ford模板
 * 作者: RainbowBird
 * 日期: 2020-10-29
 */

#include <iostream>
#include <cstring>
using namespace std;

namespace Edge {
    int head[105], tot = 0;
    struct Edge {
        int u, v, w, next;
    } e[105 * 2];

    void init() {
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v, int w) {
        e[++tot].u = u;
        e[tot].v = v;
        e[tot].w = w;
        e[tot].next = head[u];
        head[u] = tot;
    }
}

int n, m, s;
int dis[105];

int BellmanFord(int s) {
    memset(dis, 127, sizeof(dis));
    dis[s] = 0;

    for (int x = 1; x <= n; x++) {
        for (int i = Edge::head[x]; i; i = Edge::e[i].next) {
            int v = Edge::e[i].v;
            if (dis[v] > dis[x] + Edge::e[i].w) {
                dis[v] = dis[x] + Edge::e[i].w;
            }
        }
    }

    // 验证负权回路
    for (int i = 1; i <= m; i++) {
        if (dis[Edge::e[i].u] + Edge::e[i].w < dis[Edge::e[i].v])
            return false;
    }

    return true;
}

int main() {
    cin >> n >> m >> s;
    Edge::init();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge::addEdge(u, v, w);
        Edge::addEdge(v, u, w);
    }

    BellmanFord(s);

    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";

    cout << endl;
    return 0;
}
