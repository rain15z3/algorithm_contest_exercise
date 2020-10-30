/* P10011 愤怒的牛
 * 来源: 信息学奥赛一本通 提高篇
 * 作者: RainbowBird
 * 日期: 2020-08-29
 * 算法: 二分答案
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> a;

int check(int x) {
    int last = a[0]; // 先塞第一个牛棚
    int count = 1;
    
    // 遍历区间
    for (auto it = a.begin() + 1; it != a.end(); it++) {
        // 如果当前的牛棚和上一个牛棚的距离大于或等于最大值
        if (*it - last >= x) {
            last = *it;
            count++;
        }

        // 如果可以把牛全部放进牛棚
        if (count >= m) return true;
    }
    
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end(), less<int>());

    // [l, r]为闭区间
    int l = a[0], r = a[n-1]; // l, r, mid都为距离
    while (l <= r) {
        int mid = (l + r) / 2; // mid为最短距离的最大值

        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    cout << r << endl;
    return 0;
}
