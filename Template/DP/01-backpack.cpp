/* 01背包模板
 * 作者: RainbowBird
 * 日期: 2020-09-04
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, m;
int w[105], v[105];
int f[105];

int main() {
    cin >> T >> m;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= m; i++) {
        for (int j = T; j >= 0; j--) {
            if (j >= w[i]) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
    }

    cout << f[T] << endl;
    return 0;
}
