#include <iostream>
using namespace std;

int n, a[100005], b[100005];
long long tot;

void merge(int l, int mid, int r) {
    int p1 = l, p2 = mid + 1;
    for (int i = l; i <= r; i++) {
        if ((p1 <= mid) && ((p2 > r) || a[p1] <= a[p2])) {
            b[i] = a[p1];
            p1++;
        } else {
            b[i] = a[p2];
            p2++;
            tot += mid - p1 + 1; // 前面所有的数都是它的逆序对
        }
    }

    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

void merge_sort(int l, int r) {
    int mid = (l + r) / 2;
    if (l < r) {
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
    }
    merge(l, mid, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    merge_sort(1, n);

    cout << tot << endl;
    return 0;
}
