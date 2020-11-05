/* P4366 最短路
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-11-04
 * 算法: Dijkstra
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 5e5 + 10;
int n, m, c, a, b;

namespace Edge
{
    int tot, head[MAXN];
    struct Edge
    {
        int u, v, w, next;
    } e[MAXN + 20 * MAXM];

    void init()
    {
        tot = 0;
        memset(head, -1, sizeof(head));
    }

    void add_edge(int u, int v, int w)
    {
        e[++tot].u = u;
        e[tot].v = v;
        e[tot].w = w;
        e[tot].next = head[u];
        head[u] = tot;
    }
} // namespace Edge

namespace Dijkstra
{
    int dis[MAXN], vis[MAXN];
    priority_queue<pair<int, int>> que;

    void init()
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 127, sizeof(dis));
    }

    void run(int s)
    {
        dis[s] = 0;
        que.push(make_pair(0, s));
        while (!que.empty())
        {
            int x = que.top().second;
            que.pop();

            if (vis[x])
                continue;
            vis[x] = 1;

            for (int i = Edge::head[x]; i; i = Edge::e[i].next)
            {
                int v = Edge::e[i].v;
                if (dis[v] > dis[x] + Edge::e[i].w)
                {
                    dis[v] = dis[x] + Edge::e[i].w;
                    que.push(make_pair(-dis[v], v));
                }
            }
        }
    }
} // namespace Dijkstra

int main()
{
    Edge::init();
    Dijkstra::init();

    cin >> n >> m >> c;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge::add_edge(u, v, w);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j <<= 1) {
            if ((i ^ j) > n) continue;
            Edge::add_edge(i, i ^ j, c * j);
        }
    }

    cin >> a >> b;
    Dijkstra::run(a);
    cout << Dijkstra::dis[b] << endl;

    return 0;
}
