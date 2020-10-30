/* P1015 回文数
 * 来源: NOIP1999
 * 作者: RainbowBird
 * 日期: 2020-09-14
 * 算法: 高精度, 字符串
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
string m;

namespace bignum {
    // 高精度加法
    string add(string a, string b) {
        int na[105], nb[105], nc[1005];
        int lena = a.length(), lenb = b.length();

        memset(na, 0, sizeof(na));
        memset(nb, 0, sizeof(nb));
        memset(nc, 0, sizeof(nc));

        for (int i = 1; i <= lena; i++) na[i] = a[lena - i] - '0';
        for (int i = 1; i <= lenb; i++) nb[i] = b[lenb - i] - '0';        
        
        for (int i = 1; i <= lena + lenb; i++) {
            nc[i] += na[i] + nb[i];
            if (nc[i] >= n) {
                nc[i + 1]++;
                nc[i] -= n;
            }
        }

        int lenc = lena + lenb + 1;
        while (lenc > 0 && nc[--lenc] == 0);

        char s[1005];
        memset(s, 0, sizeof(s));
        for (int i = lenc; i >= 1; i--)
            s[lenc - i] = nc[i] + '0';
        
        return s;
    }
}

// 进制转换
namespace todec {
    char* donum(string m) {
        char tempc[105];
        memset(tempc, 0, sizeof(tempc));
        
        for (int i = 0; i < m.length(); i++) {
            if (m[i] >= '0' && m[i] <= '9')
                tempc[i] = m[i] - '0';
            else // 处理十六进制
                tempc[i] = m[i] - 'A' + 10;
        }

        return tempc;
    }

    string dec(int n, string m) {
        int a;
        int dec = 0, cur = 0;
        string s;

        for (int i = m.length() - 1; i >= 0; i--) {
            if (n == 16) {
                switch (m[i]) {
                    case 'A':
                        a = 10;
                        break;
                    case 'B':
                        a = 11;
                        break;
                    case 'C':
                        a = 12;
                        break;
                    case 'D':
                        a = 13;
                        break;
                    case 'E':
                        a = 14;
                        break;
                    case 'F':
                        a = 15;
                        break;
                    default:
                        a = m[i] - '0';
                }
            } else {
                a = m[i] - '0';
            }

            dec += a * pow(n, cur++);
        }

        s = to_string(dec);
        return s;
    }
} // namespace todec

namespace huiwen {
    bool ishuiwen(string a) {
        int len = a.length();
        int half = len / 2;

        for (int i = 0; i < half; i++) {
            if (a[i] != a[a.length() - i - 1]) return false;
        }

        return true;
    }

    string fz(string a) {
        char temp[105];
        memset(temp, 0, sizeof(temp));
        for (int i = a.length() - 1; i >= 0; i--) {
            temp[i] = a[a.length() - i - 1];
        }
        return temp;
    }
}

int main() {
    cin >> n >> m;

    // 处理数字
    m = todec::donum(m);

    // 翻转回文串
    int total = 0;
    while (!huiwen::ishuiwen(m)) {
        total++;

        if (total > 30) {
            cout << "Impossible!" << endl;
            return 0;
        }

        // 翻转并相加
        m = bignum::add(m, huiwen::fz(m));
    }

    cout << "STEP=" << total << endl;
    return 0;
}
