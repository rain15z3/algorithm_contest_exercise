/* P1097 合并果子
 * 来源: NOIP2004
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: STL, 堆
 */

#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > heap;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        heap.push(a);
    }

    int total = 0;
    while (heap.size() != 1) {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();

        heap.push(a + b);
        total += (a + b);
    }

    cout << total << endl;
    return 0;
}
