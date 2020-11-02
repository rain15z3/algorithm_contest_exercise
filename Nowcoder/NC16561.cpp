/* NC16561 国王的游戏
 * 来源: Nowcoder
 * 作者: RainbowBird
 * 日期: 2020-11-02
 * 算法: 高精度
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;

struct Hand {
    int l, r;
    ll times;
} hand[100005];

int n, kingl, kingr;
int na[4005], nb[4005], nc[4005], nd[4005];

namespace BigNum {
    string mult(string a, string b) {
        int lena = a.length(), lenb = b.length(), lenc;

        memset(na, 0, sizeof(na));
        memset(nb, 0, sizeof(nb));
        memset(nc, 0, sizeof(nc));

        for (int i = 1; i <= lena; i++)
            na[i] = a[lena-i] - '0';
        for (int j = 1; j <= lenb; j++)
            nb[j] = b[lenb-j] - '0';

        for (int i = 1; i <= lena; i++) {
            for (int j = 1; j <= lenb; j++) {
                nc[i+j-1] += na[i] * nb[j];
            }
        }

        for (int i = 1; i <= lena + lenb; i++) {
            if (nc[i] >= 10) {
                nc[i+1] += nc[i] / 10;
                nc[i] %= 10;
            }
        }

        lenc = lena + lenb + 2;
        while (nc[--lenc] == 0);
        if (lenc < 1) lenc = 1;

        char ret[4005];
        memset(ret, 0, sizeof(ret));
        for (int i = 1; i <= lenc; i++)
            ret[i-1] = nc[lenc-i+1] + '0';
        return ret;
    }

    int cmp(int a[], int b[], int last, int len) {
        if (a[last+len] != 0) return true; // 被除数的位数比除数大

        // 逐位比较
        for (int i = len; i >= 1; i--) {
            if (a[i+last-1] > b[i]) return true;
            if (a[i+last-1] < b[i]) return false;
        }

        return true;
    }

    string divi(string a, string b) {
        int lena = a.length(), lenb = b.length();
        int lenc = lena + lenb + 2;//, lend = max(lena, lenb) + 1;

        memset(na, 0, sizeof(na)); // 被除数
        memset(nb, 0, sizeof(nb)); // 除数
        memset(nc, 0, sizeof(nc)); // 商
        memset(nd, 0, sizeof(nd)); // 余数

        for (int i = 1; i <= lena; i++)
            na[i] = a[lena-i] - '0', nd[i] = na[i];
        for (int j = 1; j <= lenb; j++)
            nb[j] = b[lenb-j] - '0';

        // i是商的位置，对齐
        for (int i = lena - lenb + 1; i >= 1; i--) {
            while (BigNum::cmp(nd, nb, i, lenb)) { // 被除数比除数大？
                // 高精度减法
                for (int j = 1; j <= lenb; j++) {
                    nd[i+j-1] -= nb[j];
                    if (nd[i+j-1] < 0) {
                        nd[i+j]--;
                        nd[i+j-1] += 10;
                    }
                }

                nc[i]++; // 商上一位
            }
        }

        while (nc[--lenc] == 0);
        if (lenc < 1) lenc = 1;
        
        char ret[4005];
        memset(ret, 0, sizeof(ret));
        for (int i = 1; i <= lenc; i++)
            ret[i-1] = nc[lenc-i+1] + '0';
        return ret;
    }

    string smax(string a, string b) {
        if (a.length() == b.length())
            return a > b ? a : b;
        return a.length() > b.length() ? a : b;
    }

    string smin(string a, string b) {
        if (a.length() == b.length())
            return a > b ? a : b;
        return a.length() > b.length() ? a : b;
    }
}

int cmp(Hand x, Hand y) {
    return x.times < y.times;
}

int main() {
    cin >> n >> kingl >> kingr;
    for (int i = 1; i <= n; i++) {
        cin >> hand[i].l >> hand[i].r;
        hand[i].times = hand[i].l * hand[i].r;
    }
    
    sort(hand+1, hand+1+n, cmp);

    string left = to_string(kingl);
    for (int i = 1; i <= n - 1; i++)
        left = BigNum::mult(left, to_string(hand[i].l));

    string ans = BigNum::divi(left, to_string(hand[n].r));
    if (ans == "0")
        cout << "1" << endl;
    else
        cout << ans << endl;
    return 0;
}