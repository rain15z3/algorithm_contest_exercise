/* P1017 进制转换
 * 来源: NOIP2000
 * 作者: RainbowBird
 * 日期: 2020-08-28
 * 算法: 负进制转换
 */

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

char nums[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int main() {
    int n, r;
    scanf("%d %d", &n, &r);

    printf("%d=", n);

    char ans[10005], cur = 0;
    while (n != 0) {
        int mod = n % r;
        n /= r;
        if (mod < 0) n++, mod = abs(r) - abs(mod);
        //printf("%d %d\n", n, mod);
        ans[cur++] = nums[mod];
    }
    
    for (int i = cur - 1; i >= 0; i--) printf("%c", ans[i]);
    printf("(base%d)\n", r);
    return 0;
}
