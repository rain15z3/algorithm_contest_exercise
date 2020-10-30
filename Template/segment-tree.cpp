/* 线段树模板
 * 作者: RainbowBird
 * 日期: 2020-09-02
 */

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll a[100005];
ll tree[100005]; // 左子树下标p*2，右子树下标p*2+1
ll lazy[100005]; // 懒惰标签

namespace st {
// p: 当前数组的下标
// l, r: 区间l-r，在数组a里面
void build(int p, int l, int r) {
    lazy[p] = 0; // 懒惰标签清空

    if (l == r) {       // 如果已经到了最小的部分
        tree[p] = a[l]; // 把当前数组a的值赋值给线段树tree[p]
        return;
    }

    int mid = (l + r) / 2;
    build(p * 2, l, mid);                    // 建立左子树
    build(p * 2 + 1, mid + 1, r);            // 建立右子树
    tree[p] = tree[p * 2] + tree[p * 2 + 1]; // 当前数的值等于子树的和
}

// len: 下传的子树区间大小
void pushdown(int p, int len) {
    // 子树节点的懒惰标记加上父亲节点的懒惰标记
    lazy[p * 2] += lazy[p];
    lazy[p * 2 + 1] += lazy[p];

    // 子树更新区间和
    tree[p * 2] += (len - len / 2) * lazy[p];
    tree[p * 2 + 1] += (len / 2) * lazy[p];

    // 清除父亲节点的懒惰标记
    lazy[p] = 0;
}

// x, y: 修改[x,y]这个区间
// num: 修改的值，加上一个数
void change(int p, int l, int r, int x, int y, int num) {
    if (x <= l && y >= r) {           // [l,r]区间包含了当前区间[x,y]
        lazy[p] += num;               // 修改区间[l,r]的懒惰标签
        tree[p] += (num * ll(r - l + 1)); // 当前区间的区间和加上左右子树的和
        return;
    }

    // 向下搜索
    pushdown(p, (r - l + 1)); // 懒惰标记下传（只下穿一层）

    int mid = (l + r) / 2;
    if (x <= mid)
        change(p * 2, l, mid, x, y, num); // 遍历左子树
    if (y > mid)
        change(p * 2 + 1, mid + 1, r, x, y, num); // 遍历右子树

    tree[p] = tree[p * 2] + tree[p * 2 + 1]; // 更新区间和（左子树和右子树的和）
}

// x, y: 需要查询的区间左右界
ll find(int p, int l, int r, int x, int y) {
    if (x <= l && y >= r) // 如果区间[l,r]被完整包含在了需要查询的区间[x,y]里面
        return tree[p]; // 返回区间[l,r]的区间和
    int mid = (l + r) / 2;

    if (lazy[p] != 0) // 如果节点含有懒惰标记
        pushdown(p, r - l + 1); // 懒惰标记下传

    ll re = 0;

    if (x <= mid) // 如果需要查询的区间在mid的左边
        re += find(p * 2, l, mid, x, y); // 搜索左子树
    if (y > mid) // 如果需要查询的区间在mid的右边
        re += find(p * 2 + 1, mid + 1, r, x, y); // 搜索右子树

    return re;
}

} // namespace st

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    st::build(1, 1, n); // 建立线段树

    for (int i = 1; i <= m; i++) {
        int op, x, y, k;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d", &x, &y, &k);
            st::change(1, 1, n, x, y, k);
        } else if (op == 2) {
            scanf("%d %d", &x, &y);
            ll ans = st::find(1, 1, n, x, y);
            printf("%lld\n", ans);
        }
    }

    return 0;
}
