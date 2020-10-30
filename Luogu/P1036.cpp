/* P1036 选数
 * 来源: NOIP2002
 * 作者: RainbowBird
 * 日期: 2020-08-19
 * 算法: NONE
 */

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

#define f(i, j, k) for (int i = (j); i < (k); i++)
const int MAXN = 0x3f3f3f;

int n, k;
int a[25], total;

int isprime(int x) {
    if (x < 2) return false; // 小于2的数都不是质数
    if (x != 2 && x % 2 == 0) return false; // 不是2且能被2整除的数都不是质数
    for (int i = 3; i <= int(sqrt(x)); i += 2) // 每次循环加2
        if (x % i == 0) return false;
    return true;
}

void dfs(int step, int sum, int start) {
    if (step == k) {
        if (isprime(sum))
            total++;
        return;
    }

    for (int i = start; i < n; i++) {
        dfs(step + 1, sum + a[i], i + 1);
    }
}

int main() {
    cin >> n >> k;
    f(i, 0, n) cin >> a[i];
    dfs(0, 0, 0);
    cout << total << endl;
    return 0;
}
