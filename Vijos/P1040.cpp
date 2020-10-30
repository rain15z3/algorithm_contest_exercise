/* P1040 高精度乘法
 * 来源: Vijos
 * 作者: RainbowBird
 * 日期: 2020-08-18
 * 算法: 高精度
 */

#include <iostream>
#include <cstring>
using namespace std;

int na[10005], nb[10005], nc[10000005];
void mult(string a, string b) {
    int lena = a.length(), lenb = b.length();

    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    memset(nc, 0, sizeof(nc));

    for (int i = 1; i <= lena; i++)
        na[i] = a[lena - i] - '0';
    for (int i = 1; i <= lenb; i++)
        nb[i] = b[lenb - i] - '0';

    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            nc[i+j-1] += na[i] * nb[j];
        }
    }

    for (int i = 1; i < lena + lenb; i++) {
        if (nc[i] >= 10) {
            nc[i+1] += nc[i] / 10;
            nc[i] %= 10;
        }
    }

    int lenc = lena + lenb + 1;
    while (nc[--lenc] == 0);

    //cout << lenc << endl;
    for (int i = lenc; i >= 1; i--) {
        cout << nc[i];
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    mult(a, b);
    return 0;
}
