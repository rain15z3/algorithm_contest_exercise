/* P10000 活动安排
 * 来源: 信息学奥赛一本通 提高篇
 * 作者: RainbowBird
 * 日期: 2020-08-29
 * 算法: 贪心-区间覆盖
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, total;
vector<pair<int, int> > Node;

int cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        Node.push_back({x, y});
    }

    sort(Node.begin(), Node.end(), cmp);

    int last = Node.begin()->second;
    total++;
    
    for (auto it = Node.begin() + 1; it != Node.end(); it++) {
        if (it->first >= last) {
            last = it->second;
            total++;
        }
    }

    cout << total << endl;
    return 0;
}
