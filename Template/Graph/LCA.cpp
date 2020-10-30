/* 倍增求LCA模板
 * 作者: RainbowBird
 * 日期: 2020-10-04
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 500005;
int n, m, s;

// 链式前向星
namespace Edge {
    int head[MAXN * 2], tot = 1;
    struct Edge {
        int u, v, w, next;
    } e[MAXN * 2];

    void init() {
        tot = 1;
        memset(e, 0, sizeof(e));
        memset(head, -1, sizeof(head));
    }

    void add_edge(int u, int v, int w) {
        e[tot].u = u;
        e[tot].v = v;
        e[tot].w = w;
        e[tot].next = head[u];
        head[u] = tot++;
    }
};

namespace LCA {
    int lg[MAXN];
    int pre[MAXN][30];
    int depth[MAXN];

    // 初始化，记录各个节点的深度和2^i级的祖先
    void dfs(int x, int fath) {
        pre[x][0] = fath;
        depth[x] = depth[fath] + 1;

        for (int i = 1; i <= lg[depth[x]]; i++) {
            pre[x][i] = pre[pre[x][i - 1]][i - 1];
        }

        for (int i = Edge::head[x]; i; i = Edge::e[i].next) {
            if (Edge::e[i].v != fath) {
                dfs(Edge::e[i].v, x);
            }
        }
    }

    int lca(int x, int y) {
        if (depth[x] < depth[y])
            swap(x, y);
        
        while (depth[x] > depth[y]) {
            x = pre[x][lg[depth[x] - depth[y]] - 1]; // x往上跳
        }

        if (x == y) return x;

        for (int i = lg[depth[x]] - 1; i >= 0; i--) { // x和y一起往上跳
            if (pre[x][i] != pre[y][i]) {
                x = pre[x][i];
                y = pre[y][i];
            }
        }

        return pre[x][0]; // 跳最后一次
    }
}

int main() {
    cin >> n >> m >> s;
    Edge::init();

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        Edge::add_edge(u, v, 0);
        Edge::add_edge(v, u, 0);
    }

    for(int i = 1; i <= n; i++) // 常数优化
		LCA::lg[i] = LCA::lg[i - 1] + (1 << LCA::lg[i - 1] == i);
    
    LCA::dfs(s, 0); // 从根节点开始建立倍增树

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        cout << LCA::lca(x, y) << endl;
    }

    return 0;
}
