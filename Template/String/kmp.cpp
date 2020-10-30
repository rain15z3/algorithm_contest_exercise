/* KMP模板
 * 作者: RainbowBird
 * 日期: 2020-09-24
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[105], b[105];
int n, m, p[105];

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
        while (j > 0 && b[j+1] != a[i]) j = p[j];
        if (b[j+1] == a[i]) j++;
        if (j == m) {
            cout << i - m + 1 << endl;
            j = p[j];
        }
    }
}

int main() {
    cin >> a + 1 >> b + 1;
    n = strlen(a + 1), m = strlen(b + 1);

    pre();
    kmp();

    return 0;
}
