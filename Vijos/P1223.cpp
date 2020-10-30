// /* P1223 麦森数
//  * 来源: Vijos
//  * 作者: RainbowBird
//  * 日期: 2020-08-20
//  * 算法: 快速幂, 高精度
//  */

// #include <iostream>
// #include <cstring>
// using namespace std;

// int na[100005], nb[100005], nc[10000005];
// char c[1000005];

// string mult(string a, string b) {
//     int lena = a.length(), lenb = b.length();
//     for (int i = 1; i <= lena; i++) na[i] = a[lena-i] - '0';
//     for (int i = 1; i <= lenb; i++) nb[i] = b[lenb-i] - '0';

//     for (int i = 1; i <= lena; i++) {
//         for (int j = 1; j <= lenb; j++) {
//             nc[i+j-1] += na[i] * nb[j];
//         }
//     }

//     for (int i = 1; i < lena + lenb; i++) {
//         if (nc[i] >= 10) {
//             nc[i+1] += nc[i] / 10;
//             nc[i] %= 10;
//         }
//     }

//     int lenc = lena + lenb + 1;
//     while (nc[--lenc] == 0);

//     for (int i = 0; i < lenc; i++) c[i] = nc[lenc-i] + '0';
//     return c;
// }

// string qpow(string a, int n) {
//     string ans = "1";
//     while (n > 0) {
//         if (n % 2 == 1) {
//             ans = mult(ans, a);
//             //cout << ans << endl;
//         }
//         a = mult(a, a);
//         n /= 2;
//     }
//     return ans;
// }

// int main() {
//     int a;
//     cin >> a;
//     cout << qpow("2", a) << endl;
//     return 0;
// }

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int p, a[100002], b[520];
void fz(int n) {
    int i, j;
    if (n == 0)
        return;
    fz(n / 2);
    for (i = 1; i <= 500; i++)
        for (j = 1; j <= 500; j++)
            if (n % 2 == 0)
                a[i + j - 1] = a[i + j - 1] + b[i] * b[j];
            else
                a[i + j - 1] = a[i + j - 1] + b[i] * b[j] * 2;
    for (i = 1; i <= 500; i++) {
        b[i] = a[i] % 10;
        a[i + 1] = a[i + 1] + a[i] / 10;
    }
    memset(a, 0, sizeof(a));
}
int main() {
    int i;
    scanf("%d", &p);
    b[1] = 1;
    fz(p);
    cout << int((log(2) / log(10)) * p + 1) << endl;
    for (i = 500; i > 1; i--) {
        cout << b[i];
        if (i % 50 == 1)
            cout << endl;
    }
    cout << b[1] - 1 << endl;
    return 0;
}
