/* 完全背包模板
 * 作者: RainbowBird
 * 日期: 2020-09-05
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll T, m;
int w[10005], v[10005];
ll f[10000005];

int main() {
    cin >> T >> m;
    memset(w, 0, sizeof(w));
    memset(v, 0, sizeof(v));
    memset(f, 0, sizeof(f));
    for (ll i = 1; i <= m; i++)
        cin >> w[i] >> v[i];

    for (ll i = 1; i <= m; i++) {
        for (ll j = 0; j <= T; j++) {
            if (j >= w[i]) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
    }

    cout << f[T] << endl;
    return 0;
}
