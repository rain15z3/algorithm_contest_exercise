/* NC14369 最短路
 * 来源: Nowcoder
 * 作者: RainbowBird
 * 日期: 2020-11-05
 * 算法: SPFA
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

const int MAXN = 200005;
int n, m;

namespace Edge {
    int head[MAXN], cur;

    struct Edge {
        int u, v, w, next;
    } e[MAXN];

    void init() {
        cur = 0;
        memset(head, -1, sizeof(head));
    }

    void add_edge(int u, int v, int w) {
        e[++cur].u = u;
        e[cur].v = v;
        e[cur].w = w;
        e[cur].next = head[u];
        head[u] = cur;
    }
}

namespace SPFA {
    int dis[MAXN], vis[MAXN];
    queue<int> que;

    void init() {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
    }

    void run(int s) {
        dis[s] = 0;
        vis[s] = 1;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            vis[u] = 0;
            for (int i = Edge::head[u]; i; i = Edge::e[i].next) {
                int v = Edge::e[i].v;
                if (dis[v] > dis[u] + Edge::e[i].w) {
                    dis[v] = dis[u] + Edge::e[i].w;
                    if (!vis[v]) {
                        vis[v] = 1;
                        que.push(v);
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    Edge::init();
    SPFA::init();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge::add_edge(u, v, w);
    }

    SPFA::run(1);
    for (int i = 2; i <= n; i++) {
        cout << SPFA::dis[i] << endl;
    }

    return 0;
}
