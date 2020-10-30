/* LIS - 最长上升子序列
 * 复杂度：O(nlogn)
 * 作者：RainbowBird
 * 日期：2020年7月2日
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;

int main() {
    int n, a[1005], f[1005];
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = INF;
    }

    f[1] = a[1];
    int len = 1;

    for (int i = 2; i <= n; i++) {
        int l = 0, r = len, mid;
        if (a[i] > f[len])
            f[++len] = a[i];
        else {
            // 二分查找
            while (l < r) {
                mid = (l + r) / 2;
                if (f[mid] > a[i])
                    r = mid;
                else // 向前查找
                    l = mid + 1;
            }
            
            f[l] = min(a[i], f[l]); // 更新最小元素
        }
    }

    cout << len << endl;
    return 0;
}