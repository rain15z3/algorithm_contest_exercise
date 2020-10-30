/* P3375 【模板】KMP字符串匹配
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-09-23
 * 算法: KMP
 */

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 1e6 + 5;

int n, m;
int p[MAXN];
char a[MAXN], b[MAXN];

void pre() {
    p[1] = 0;
    int j = 0;
    for (int i = 2; i <= m; i++) {
        while (j > 0 && b[j+1] != b[i]) j = p[j];
        if (b[j+1] == b[i]) j++;
        p[i] = j;
    }
}

void kmp() {
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j > 0 && b[j+1] != a[i]) j = p[j]; // 不能匹配，指针前移
        if (b[j+1] == a[i]) j++; // 可以匹配，指针后移

        if (j == m) { // 子串匹配完成
            cout << i - m + 1 << endl;
            j = p[j];
        }
    }
}

int main() {
    cin >> a + 1;
    cin >> b + 1;
    n = strlen(a + 1);
    m = strlen(b + 1);
    pre();
    kmp();

    for (int i = 1; i <= m; i++)
        cout << p[i] << " ";

    cout << endl;
    return 0;
}
