/* NC16649 校门外的树
 * 来源: NOIP2005
 * 作者: RainbowBird
 * 日期: 2020-08-30
 * 算法: 离散化, 前缀和
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int pos; // 位置
    int num; // 前缀和
} a[100005];

int cmp(Node a, Node b) {
    return a.pos < b.pos;
}

int l, m;

int main() {
    cin >> l >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        // 离散化存储
        a[i*2-1].pos = x;   // 左端点的位置
        a[i*2-1].num = 1;   // 左端点用1表示
        a[i*2].pos = y + 1; // 右端点的位置（差分用，所以这里是y+1）
        a[i*2].num = -1;    // 右端点用-1表示
    }

    sort(a + 1, a + m * 2 + 1, cmp); // 按照左端点的位置升序排列

    // 前缀和
    int sum = 0, total = 0;
    for (int i = 1; i <= m * 2; i++) { // 一共有2m个点，全部遍历一遍
        sum += a[i].num; // sum用来存储当前状态

        // 当sum的值由0变为1时说明中间经过了一段没有树的区间
        if (sum == 1 && a[i].num == 1) {
            // 这时a[i]是左端点，a[i-1]是上个区间的右端点
            total += a[i].pos - a[i-1].pos; // 加上区间长度
        }
    }

    // 最后一个右端点到区间终点的距离
    total += l - a[m*2].pos + 1;

    cout << total << endl;
    return 0;
}
