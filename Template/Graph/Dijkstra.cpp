/* Dijkstra模板
 * 作者: RainbowBird
 * 日期: 2020-09-25
 */

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int MAXN = 5 * 10e5 + 5;
int n, m, s;
int dis[MAXN], book[MAXN], head[MAXN], cnt = 1;
priority_queue<pair<int, int> > que;

// 链式前向星
struct Edge {
    int next, to, w;
} e[MAXN];

// 加一条边
void add(int u, int v, int w) {
    e[cnt].w = w;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

int main() {
    cin >> n >> m >> s;
    memset(head, -1, sizeof(head));
    memset(book, 0, sizeof(book));
    fill(dis, dis + MAXN, INF);

    // 读入边
    for (int i = 1; i <= m; i++) {
        // 有向带权图
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    // Dijkstra
    dis[s] = 0;
    que.push({0, s});
    while (!que.empty()) {
        int x = que.top().second;
        que.pop();

        // 请勿重复查找
        if (book[x]) continue;
        book[x] = 1;

        // 扫描所有出边
        for (int i = head[x]; i != -1; i = e[i].next) {
            int v = e[i].to;
            if (dis[v] > dis[x] + e[i].w) {
                dis[v] = dis[x] + e[i].w; // 松弛
                que.push({-dis[v], v}); // 用pair实现可以把dis值赋值成负数就可以实现小根堆
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    
    cout << endl;
    return 0;
}
