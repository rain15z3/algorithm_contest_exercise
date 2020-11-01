/* P1098 合唱队形
 * 来源: NOIP 2004
 * 作者: RainbowBird
 * 日期: 2020-10-19
 * 算法: LIS
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, a[105], f1[105], f2[105];

int main() {
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    fill(f1+1, f1+1+n, 1);
    fill(f2+1, f2+1+n, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            if (a[i] > a[j]) {
                f1[i] = max(f1[i], f1[j] + 1);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= i + 1; j--) {
            if (a[i] > a[j]) {
                f2[i] = max(f2[i], f2[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f1[i] + f2[i] - 1);
    }

    cout << n - ans << endl;
    return 0;
}

