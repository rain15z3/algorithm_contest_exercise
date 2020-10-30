/* P10005 数列极差
 * 来源: 信息学奥赛一本通 提高篇
 * 作者: RainbowBird
 * 日期: 2020-08-29
 * 算法: NONE
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
priority_queue<int> heapl;
priority_queue<int, vector<int>, greater<int> > heapg;

int main() {
    cin >> n;
    int x;
    while (cin >> x) {
        if (x == 0) break;
        heapg.push(x); // 大根堆
        heapl.push(x); // 小根堆
    }

    // 找最大值
    while (heapg.size() > 1) {
        int a, b, c;
        a = heapg.top(); heapg.pop();
        b = heapg.top(); heapg.pop();
        c = a * b + 1;
        heapg.push(c);
    }
    
    // 找最小值
    while (heapl.size() > 1) {
        int a, b, c;
        a = heapl.top(); heapl.pop();
        b = heapl.top(); heapl.pop();
        c = a * b + 1;
        heapl.push(c);
    }

    cout << heapg.top() - heapl.top() << endl;
    return 0;
}
