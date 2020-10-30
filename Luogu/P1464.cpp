/* P1464 Function
 * Author: RainbowBird
 * Date: 2020-08-14
 * Algorithm: Memorized search
 */

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
using namespace std;
typedef long long ll;

ll mem[25][25][25];

ll dg(ll a, ll b, ll c) {
    if (a > 20) a = 21;
    if (b > 20) b = 21;
    if (c > 20) c = 21;

    //printf("[%d %d %d]\n", a, b, c);
    if (a <= 0 || b <= 0 || c <= 0) return 1; // Negative judge

    if (mem[a][b][c]) return mem[a][b][c]; // Memorized
    if (a > 20 || b > 20 || c > 20) return mem[a][b][c] = dg(20, 20, 20);
    if (a < b && b < c)
        return mem[a][b][c] = dg(a, b, c-1) + dg(a, b-1, c-1) - dg(a, b-1, c);
    return mem[a][b][c] = dg(a-1, b, c) + dg(a-1, b-1, c) + dg(a-1, b, c-1) - dg(a-1, b-1, c-1);
}

int main() {
    ll a, b, c;
    //freopen("P1464.out", "w", stdout);

    while (scanf("%lld %lld %lld", &a, &b, &c) == 3) {
        memset(mem, 0, sizeof(mem));
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dg(a, b, c));
    }

    return 0;
}
