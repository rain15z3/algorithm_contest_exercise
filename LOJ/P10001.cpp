/* P10001 区间种树
 * 来源: 信息学奥赛一本通 提高篇
 * 作者: RainbowBird
 * 日期: 2020-08-29
 * 算法: 贪心-区间选点
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
    int b, e, t;
};

int n, h, road[30005], ans;
vector<Node> a;

int cmp(Node a, Node b) {
    return a.e < b.e;
}

int main() {
    cin >> n >> h;
    for (int i = 1; i <= h; i++) {
        int b, e, t;
        cin >> b >> e >> t;
        a.push_back({b, e, t});
    }

    memset(road, 0, sizeof(road));
    sort(a.begin(), a.end(), cmp);

    for (auto it = a.begin(); it != a.end(); it++) {
        int total = 0;

        // 统计已选点个数
        for (int i = it->b; i <= it->e; i++) {
            if (road[i]) total++;
        }
        
        // 如果数量不够
        if (total < it->t) {
            // 区间从后向前遍历
            for (int j = it->e; j >= it->b; j--) {
                if (total == it->t) break;
                if (!road[j]) {
                    road[j] = 1;
                    total++;
                    ans++;
                }
            }
        }
    }

    // 遍历区间
    //for (int i = 0; i <= n; i++) if (road[i]) ans++;

    cout << ans << endl;
    return 0;
}
