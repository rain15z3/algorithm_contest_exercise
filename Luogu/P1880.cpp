/* P1880 石子合并
 * 来源: NOI 1995
 * 作者: RainbowBird
 * 日期: 2020-10-09
 * 算法: 区间DP
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, a[205];
int sum[205], fmaxn[205][205], fminn[205][205];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i]; // 环处理
    }

    for (int i = 1; i <= n * 2; i++) {
        sum[i] = sum[i-1] + a[i];
    }
    
    for (int p = 1; p <= n; p++) { // 阶段
        for (int i = 1, j = i + p; (i < n * 2) && (j < n * 2); i++, j = i + p) {
            fminn[i][j] = 0x7f7f7f7f;
            for (int k = i; k < j; k++) {
                fmaxn[i][j] = max(fmaxn[i][j], fmaxn[i][k] + fmaxn[k+1][j] + sum[j] - sum[i-1]);
                fminn[i][j] = min(fminn[i][j], fminn[i][k] + fminn[k+1][j] + sum[j] - sum[i-1]);
            }
        }
    }

    int maxn = 0, minn = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, fmaxn[i][i+n-1]);
        minn = min(minn, fminn[i][i+n-1]);
    }

    cout << minn << endl;
    cout << maxn << endl;
    return 0;
}
