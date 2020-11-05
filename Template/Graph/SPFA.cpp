/* SPFA模板
 * 作者: RainbowBird
 * 日期: 2020-10-29
 */

#include <iostream>
#include <cstring>
#include <queue> 
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
int dis[105], vis[105], tot[105];
queue<int> que;

int spfa(int s) {
    dis[s] = 0;
    vis[s] = 1;
    que.push(s);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        vis[x] = 0;

        for (int i = Edge::head[x]; i; i = Edge::e[i].next) {
            int v = Edge::e[i].v;
            if (dis[v] > dis[x] + Edge::e[i].w) {
                dis[v] = dis[x] + Edge::e[i].w;
                tot[v] = tot[x] + 1;

                if (!vis[v]) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    Edge::init();
    memset(dis, 127, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge::addEdge(u, v, w);
        Edge::addEdge(v, u, w);
    }

    spfa(s);

    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    
    cout << endl;
    return 0;
}
