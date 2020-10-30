/* LIS - 最长上升子序列
 * 复杂度：O(n^2)
 * 作者：RainbowBird
 * 日期：2020年7月2日
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[1005];
    int f[1005];    // 最长上升子序列
    int fn[1005];   // 最长不升子序列

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        fn[i] = 1; // 初始化
        for (int j = 1; j < i; j++) {
            if (a[i] <= a[j]) {
                fn[i] = max(fn[i], fn[j] + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        f[i] = 1; // 初始化
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }

    int af = 0, afn = 0;
    for (int i = 1; i <= n; i++) {
        af = max(f[i], af);
        afn = max(fn[i], afn);
    }

    cout << afn << endl;
    cout << af << endl;
    
    return 0;
}
