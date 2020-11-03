#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
struct Computer {
    int a, b;
} com[100005];

int cmp(Computer x, Computer y) {
    return x.a > y.a;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> com[i].a >> com[i].b;

    sort(com + 1, com + 1 + n, cmp);

    int maxn = com[1].b, tot = 0;
    for (int i = 2; i <= n; i++) {
        if (com[i].b < maxn) tot++;
        else maxn = com[i].b;
    }

    cout << tot << endl;
    return 0;
}
