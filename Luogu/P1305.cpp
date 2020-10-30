#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

struct Node {
    char f, l, r;
};

map<char, Node> tree;
map<char, int> book;

void dfs(char a) {
    if (!book[a]) {
        book[a] = 1;
        cout << tree[a].f; // 输出

        if (tree[a].l != '*')
            dfs(tree[a].l); // 遍历左子树
        if (tree[a].r != '*')
            dfs(tree[a].r); // 遍历右子树
    }
}

int main() {
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    char a = str[0], b = str[1], c = str[2];
    tree[a] = Node{a, b, c};
    book[a] = 0;

    for (int i = 2; i <= n; i++) {
        string str;
        cin >> str;
        char a = str[0], b = str[1], c = str[2];
        tree[a] = Node{a, b, c};
        book[a] = 0;
    }

    dfs(a);

    /*for (auto iter = tree.begin(); iter != tree.end(); iter++) {
        cout << iter->first << ":" << iter->second.l << " " << iter->second.r << endl;
    }*/

    return 0;
}
