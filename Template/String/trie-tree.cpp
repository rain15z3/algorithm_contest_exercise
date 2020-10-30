/* 字典树模板
 * 作者: RainbowBird
 * 日期: 2020-08-31
 */

#include <iostream>
#include <cstring>
using namespace std;

int trie[10005][26]; // 最大深度 最大字符集
int book[10005];     // 用于标识是否为终结点
int cur = 1;         // 从1开始因为0是根节点

void insert(string str) {
    int p = 0;                  // 从根节点开始遍历
    for (int i = 0; i < str.length(); i++) {
        int c = str[i] - 'a';   // 把小写字母转换为数字（从0-25，分别对应a-z）
        if (!trie[p][c])        // 如果当前节点没有一条为c的边
            trie[p][c] = cur++; // 添加一条边，边总数加1
        p = trie[p][c];         // 指针移到当前节点
    }

    book[p] = 1;                // 遍历完成，在最后一条边上打上结束标记
}

int search(string str) {
    int p = 0;
    for (int i = 0; i < str.length(); i++) {
        int c = str[i] - 'a';
        if (!trie[p][c]) return false; // 如果当前字母的边没有找到则返回false
        p = trie[p][c];                // 指针指向当前节点
    }
    
    return book[p] == 1;               // 如果当前边有结束标记则说明找到了
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        insert(a);
    }

    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;
        if (search(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
