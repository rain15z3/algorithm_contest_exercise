/* NC20861 兔子的逆序对
 * 来源: Nowcoder
 * 作者: RainbowBird
 * 日期: 2020-11-03
 * 算法: 归并排序
 */

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int n, m;
int a[100005], b[100005];
ll tot;

int qread() {
    int base = 1, k = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-') base = -1;
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        k = k * 10 + (ch - '0');
        ch = getchar();
    }

    return k * base;
}

void merge(int l, int mid, int r) {
    int p1 = l, p2 = mid + 1;
    for (int i = l; i <= r; i++) {
        if ((p1 <= mid && (p2 > r || a[p1] <= a[p2]))) {
            b[i] = a[p1];
            p1++;
        } else {
            b[i] = a[p2];
            p2++;
            tot += mid - p1 + 1;
        }
    }

    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

void merge_sort(int l, int r) {
    int mid = (l + r) >> 1;
    if (l < r) {
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
    }

    merge(l, mid, r);
}

int main() {
    n = qread();
    for (int i = 1; i <= n; i++)
        a[i] = qread();

    merge_sort(1, n);

    m = qread();
    tot %= 2;
    
    while (m--) {
        int l, r;
        l = qread();
        r = qread();
        int p = (r - l + 1) * (r - l) / 2;
        if (p & 1) tot ^= 1;
        tot == 0 ? printf("like\n") : printf("dislike\n");
    }

    return 0;
}
