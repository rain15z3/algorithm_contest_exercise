// /* P1182 数列分段 Section II
//  * 来源: Luogu
//  * 作者: RainbowBird
//  * 日期: 2020-09-17
//  * 算法: 二分答案
//  */

// #include <iostream>
// using namespace std;

// int n, m;
// int a[100005];

// int check(int x) {
//     int total = 0;

//     for (int i = 1; i <= n; i++) {

//     }

//     return total == m;
// }

// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];

//     int l = 0, r = 10e9, mid;
//     while (l <= r) {

//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], l, r, mid, ans;
inline bool check(int x) {
    int tot = 0, num = 0;
    for (int i = 1; i <= n; i++) {
        if (tot + a[i] <= x)
            tot += a[i];
        else
            tot = a[i], num++;
    }
    return num >= m;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), l = max(l, a[i]), r += a[i];
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}
