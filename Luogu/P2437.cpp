/* P2437 蜜蜂路线
 * Author: RainbowBird
 * Date: 2020-08-14
 * Algorithm: Fibonacci, high precision
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;

string myplus(string a, string b) {
    int na[1005], nb[1005], nc[1005];
    int lena = a.length(), lenb = b.length();
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    memset(nc, 0, sizeof(nc));

    for (int i = 0; i < lena; i++) na[i] = a[lena - i - 1] - '0';
    for (int i = 0; i < lenb; i++) nb[i] = b[lenb - i - 1] - '0';

    for (int i = 0; i < max(lena, lenb); i++) {
        nc[i] += na[i] + nb[i];
        if (nc[i] >= 10) {
            nc[i] -= 10;
            nc[i+1]++;
        }
    }

    int len = max(lena, lenb) + 1;
    while (!nc[len]) len--;

    char ch[1001];
    for (int i = len; i >= 0; i--) {
        ch[len - i] = nc[i] + '0';
    }

    return ch;
}

int main() {
    scanf("%d %d", &n, &m);
    
    string dp[1005];
    dp[1] = "1";
    dp[2] = "1";
    for (int i = 3; i <= m - n + 1; i++) {
        dp[i] = myplus(dp[i-1], dp[i-2]);
        //cout << dp[i] << endl;
    }

    cout << dp[m-n+1] << endl;
    return 0;
}
