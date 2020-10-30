/* P2580 于是他错误的点名开始了
 * 来源: 洛谷
 * 作者: RainbowBird
 * 日期: 2020-08-31
 * 算法: 字典树
 */

#include <iostream>
#include <cstring>
using namespace std;

int tree[1000005][26];
int book[1000005];
int cur = 1;

void insert(string str) {
    int p = 0;
    for (int i = 0; i < str.length(); i++) {
        int c = str[i] - 'a';
        if (!tree[p][c]) {      // 如果不存在
            tree[p][c] = cur++; // 存入
        }

        p = tree[p][c];         // 指针移动到刚刚的位置
    }

    book[p] = 1; // 终止标识
}

int search(string str) {
    int p = 0;
    for (int i = 0; i < str.length(); i++) {
        int c = str[i] - 'a';
        if (!tree[p][c]) return 0; // 没找到直接返回false
        p = tree[p][c]; // 指针移动到刚刚的位置
    }

    // 判断当前位置是否有终止标识
    if (book[p] == 1) {
        book[p] = 2; // 做标记，标识已经点过一次名字
        return 1;
    } else {
        return 2;
    }
}

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        insert(a); // 插入
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;

        int status = search(a);

        if (status == 0) {
            cout << "WRONG" << endl;
        } else if (status == 1) {
            cout << "OK" << endl;
        } else if (status == 2) {
            cout << "REPEAT" << endl;
        }
    }

    return 0;
}
