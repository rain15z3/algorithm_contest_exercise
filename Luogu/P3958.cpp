/* P3958 奶酪
 * 来源: NOIP 2017
 * 作者: RainbowBird
 * 日期: 2020-10-26
 * 算法: 并查集
 */

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

int T;
int fath[1005], top[1005], bottom[1005];

struct Pos {
    ll x, y, z;
} point[1005];

ll dis(Pos a, Pos b) {
    return pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2);
}

int getf(int x) {
    if (fath[x] == x) return x;
    return fath[x] = getf(fath[x]);
}

int main() {
    cin >> T;
    while (T--) {
        memset(fath, 0, sizeof(fath));
        memset(top, 0, sizeof(top));
        memset(bottom, 0, sizeof(bottom));
        memset(point, 0, sizeof(point));

        ll n, h, r;
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) // 初始化并查集
            fath[i] = i;

        int tcur = 0, bcur = 0;
        for (int i = 1; i <= n; i++) {
            cin >> point[i].x >> point[i].y >> point[i].z;

            if (point[i].z + r >= h) // 与奶酪顶端相交
                top[++tcur] = i;

            if (point[i].z - r <= 0) // 与奶酪底端相交
                bottom[++bcur] = i;
                
            // 合并并查集
            for (int j = 1; j < i; j++) {
                if (pow((point[i].x - point[j].x), 2) + pow((point[i].y - point[j].y), 2) > 4 * r * r) continue;
                if (dis(point[i], point[j]) <= 4 * r * r) { // 两球相交
                    int x = getf(i);
                    int y = getf(j);

                    if (x != y) {
                        fath[x] = y;
                    }
                }
            }
        }

        bool flag = false;
        for (int i = 1; i <= tcur; i++) {
            if (flag) break;
            for (int j = 1; j <= bcur; j++) {
                if (getf(top[i]) == getf(bottom[j])) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
