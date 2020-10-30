// /* P1047 最小公倍数
//  * 来源: Vijos
//  * 作者: RainbowBird
//  * 日期: 2020-08-19
//  * 算法: LCM, GCD, 高精度
//  */

// #include <iostream>
// #include <cstring>
// using namespace std;
// #define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
// typedef long long ll;

// string mult(string a, string b) {
//     int na[105], nb[105], nc[10005];

//     memset(na, 0, sizeof(na));
//     memset(nb, 0, sizeof(nb));
//     memset(nc, 0, sizeof(nc));

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
//     while (lenc > 0 && nc[--lenc] == 0);

//     char c[10005];
//     for (int i = lenc; i >= 1; i--) c[lenc-i] = nc[i] + '0';
//     return c;
// }

// string sub(string a, string b) {
//     int na[105], nb[105], nc[10005];

//     memset(na, 0, sizeof(na));
//     memset(nb, 0, sizeof(nb));
//     memset(nc, 0, sizeof(nc));

//     int lena = a.length(), lenb = b.length();
//     for (int i = 1; i <= lena; i++) na[i] = a[lena-i] - '0';
//     for (int i = 1; i <= lenb; i++) nb[i] = b[lenb-i] - '0';

//     for (int i = 1; i <= lena + lenb; i++) {
//         nc[i] += na[i] - nb[i];
//         if (nc[i] < 0) {
//             nc[i+1]--;
//             nc[i] += 10;
//         }
//     }

//     int lenc = lena + lenb + 1;
//     while (lenc > 0 && nc[--lenc] == 0);

//     char c[10005];
//     for (int i = lenc; i >= 1; i--) c[lenc-i] = nc[i] + '0';
//     return c;
// }

// string divi(string a, string b) {
//     int nc[105];
//     int len = a.length() - b.length() + 1;
//     for (int i = len; i > 0; i--) {
//         memset(nc, 0, sizeof(nc));
//     }
// }

// string gcd(string a, string b) {
//     string c;

// }

// string lcm(string a, string b) {
//     return divi(mult(a, b), gcd(a, b));
// }

// int main() {
//     string a, b;
//     cin >> a >> b;
//     cout << sub(a, b) << endl;
//     return 0;
// }
#include <algorithm>
#include <iostream>
using namespace std;
const int L = 10005;
string mul(string a, string b) {
    string s;
    int na[L], nb[L], nc[L], La = a.size(), Lb = b.size();
    fill(na, na + L, 0);
    fill(nb, nb + L, 0);
    fill(nc, nc + L, 0);
    for (int i = La - 1; i >= 0; i--)
        na[La - i] = a[i] - '0';
    for (int i = Lb - 1; i >= 0; i--)
        nb[Lb - i] = b[i] - '0';
    for (int i = 1; i <= La; i++)
        for (int j = 1; j <= Lb; j++)
            nc[i + j - 1] += na[i] * nb[j];
    for (int i = 1; i <= La + Lb; i++)
        nc[i + 1] += nc[i] / 10, nc[i] %= 10;
    if (nc[La + Lb])
        s += nc[La + Lb] + '0';
    for (int i = La + Lb - 1; i >= 1; i--)
        s += nc[i] + '0';
    return s;
}
int sub(int *a, int *b, int La, int Lb) {
    if (La < Lb)
        return -1; //如果a小于b，则返回-1
    if (La == Lb) {
        for (int i = La - 1; i >= 0; i--)
            if (a[i] > b[i])
                break;
            else if (a[i] < b[i])
                return -1; //如果a小于b，则返回-1
    }
    for (int i = 0; i < La; i++) //高精度减法
    {
        a[i] -= b[i];
        if (a[i] < 0)
            a[i] += 10, a[i + 1]--;
    }
    for (int i = La - 1; i >= 0; i--)
        if (a[i])
            return i + 1; //返回差的位数
    return 0;             //返回差的位数
}
string div(string n1, string n2, int nn) {
    string s, v; // s存商,v存余数
    int a[L], b[L], r[L], La = n1.size(), Lb = n2.size(), i, tp = La;
    fill(a, a + L, 0);
    fill(b, b + L, 0);
    fill(r, r + L, 0); //数组元素都置为0
    for (i = La - 1; i >= 0; i--)
        a[La - 1 - i] = n1[i] - '0';
    for (i = Lb - 1; i >= 0; i--)
        b[Lb - 1 - i] = n2[i] - '0';
    if (La < Lb || (La == Lb && n1 < n2)) {
        cout << 0 << endl;
        return n1;
    }
    int t = La - Lb;                  //除被数和除数的位数之差
    for (int i = La - 1; i >= 0; i--) //将除数扩大10^t倍
        if (i >= t)
            b[i] = b[i - t];
        else
            b[i] = 0;
    Lb = La;
    for (int j = 0; j <= t; j++) {
        int temp;
        while ((temp = sub(a, b + j, La, Lb - j)) >= 0) {
            La = temp;
            r[t - j]++;
        }
    }
    for (i = 0; i < L - 10; i++)
        r[i + 1] += r[i] / 10, r[i] %= 10; //统一处理进位
    while (!r[i])
        i--; //将整形数组表示的商转化成字符串表示的
    while (i >= 0)
        s += r[i--] + '0'; // cout<<s<<endl;
    i = tp;
    while (!a[i])
        i--;
    while (i >= 0)
        v += a[i--] + '0';
    if (v.empty())
        v = "0";
    if (nn == 1)
        return s;
    if (nn == 2)
        return v;
}
bool judge(string s) //判断s是否为全0串
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '0')
            return false;
    return true;
}
string gcd(string a, string b) //求最大公约数
{
    string t;
    while (!judge(b)) //如果余数不为0，继续除
    {
        t = a;            //保存被除数的值
        a = b;            //用除数替换被除数
        b = div(t, b, 2); //用余数替换除数
    }
    return a;
}
int main() {
    string a, b;
    while (cin >> a >> b) {
        if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
            swap(a, b);
        }
        cout << div(mul(a, b), gcd(a, b), 1) << endl; //求最小公倍数
    }
    return 0;
}