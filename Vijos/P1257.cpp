/* P1257 水王争霸
 * 来源: NOIP2003
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 排序
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
    string name;
    string score;
} node[1005];

int cmp(Node a, Node b) {
    if (a.score == b.score) {
        return a.name < b.name;
    } else if (a.score.size() == b.score.size()) {
        return a.score > b.score;
    } else {
        return a.score.size() > b.score.size();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].name >> node[i].score;
    }

    sort(node + 1, node + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        cout << node[i].name << endl;
    }

    return 0;
}
