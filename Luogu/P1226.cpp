/* P1226 【模板】快速幂||取余运算
 * 作者：RainbowBird
 * 日期：2020-08-06
 */

#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll qpow(ll a, ll x, ll mod) {
    ll ans = 1;
    while (x > 0) {
        if (x % 2 == 1)
            ans = ans * a % mod;
        a = a * a % mod;
        x /= 2;
    }
    return ans;
}

int main() {
    ll b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld\n", b, p, k, qpow(b, p, k) % k);
    return 0;
}
