/* P1514 引水入城
 * 来源: NOIP 2010
 * 作者: RainbowBird
 * 日期: 2020-10-25
 * 算法: 搜索
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
int n, m, map[MAXN][MAXN], vis[MAXN][MAXN];
int nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int l[MAXN][MAXN], r[MAXN][MAXN];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + nxt[i][0];
        int ty = y + nxt[i][1];

        if (tx > n || ty > m || tx < 1 || ty < 1 || map[tx][ty] >= map[x][y]) continue;

        if (!vis[tx][ty])
            dfs(tx, ty);
        
        // 更新左右端点
        l[x][y] = min(l[x][y], l[tx][ty]);
        r[x][y] = max(r[x][y], r[tx][ty]);
    }
}


int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        cin >> map[i][j];
        l[i][j] = INF;
        r[i][j] = 0;
        if (i == n) l[i][j] = r[i][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        if (!vis[1][i]) dfs(1, i);
    }

    int tot = 0;
    for (int i = 1; i <= m; i++) {
        if (!vis[n][i]) tot++;
    }

    if (tot != 0) {
        cout << 0 << endl;
        cout << tot << endl;
    } else {
        int left = 1, right = r[1][1];
	
	    //统计区间数 
	    while (left <= m) {
	    	for (int i = 1; i <= m; i++) {
	    		if (l[1][i] <= left) {
	    			right = max(right, r[1][i]);
	    		}
	    	}
    
	    	left = right + 1;
	    	tot++;
	    }

        cout << 1 << endl;
        cout << tot << endl;
    }

    return 0;
}
