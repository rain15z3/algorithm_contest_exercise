/* 高精度除法
 * 作者: RainbowBird
 * 日期: 2020-09-02
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 声明变量
int na[100005], nb[100005], nc[100005], nd[100005];

string qread() {
    int cur = 0;
    char temp[100005];
    memset(temp, 0, sizeof(temp));
    char ch = getchar();
    while (ch >= '0' && ch <= '9') temp[cur++] = ch, ch = getchar();
    return temp;
}

int cmp(int a[], int b[], int last, int len) {
    if (a[last+len] != 0) return true; // 如果被除数的位数比除数大

    // 逐位比较
    for (int i = len; i > 0; i--) {
        if (a[i+last-1] > b[i]) return true;
        if (a[i+last-1] < b[i]) return false;
    }

    // 相等返回true
    return true;
}

void div(string a, string b) {
    // 声明变量
    int lena = a.length(), lenb = b.length(), lenc = lena - lenb + 2, lend = max(lena, lenb) + 1;

    // 清空变量
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    memset(nc, 0, sizeof(nc)); // 商
    memset(nd, 0, sizeof(nd)); // 余数

    // 把数字倒过来存
    for (int i = 1; i <= lena; i++) na[i] = a[lena-i] - '0', nd[i] = na[i];
    for (int i = 1; i <= lenb; i++) nb[i] = b[lenb-i] - '0';
    //for (int i = 1; i <= lena; i++) nd[i] = na[i]; // 存余数

    // 高精度除法 
    for (int i = lena - lenb + 1; i > 0; i--) { // 被除数和除数对齐
        /* 456 / 12
         *      38
         * 12 |----
         *     456
         *     36
         *     ----
         *      96
         *      96
         *     ----
         *       0
         */

        // 可以相减
        while (cmp(nd, nb, i, lenb)) {
            // 高精度减法
            for (int j = 1; j <= lenb; j++) {
                nd[i+j-1] -= nb[j];
                if (nd[i+j-1] < 0) {
                    nd[i+j]--;
                    nd[i+j-1] += 10;
                }
            }

            nc[i]++; // 商进一位
        }
    }

    // 输出商
    while (nc[--lenc] == 0);
    if (lenc <= 0) lenc++;
    for (int i = lenc; i > 0; i--) {
        cout << nc[i];
    }

    cout << endl;

    // 输出余数
    while (nd[--lend] == 0);
    if (lend <= 0) lend++;
    for (int i = lend; i > 0; i--) {
        cout << nd[i];
    }

    cout << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    string a, b;
    a = qread();
    b = qread();
    //cout << b;
    //cin >> a >> b;
    div(a, b);
    return 0;
}
