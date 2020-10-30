/* P1241 括号序列
 * 来源: Luogu
 * 作者: RainbowBird
 * 日期: 2020-09-22
 * 算法: 递推
 */

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

string a;
int book[105];

int main() {
    cin >> a;
    memset(book, 0, sizeof(book));

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == ')') {
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] == '(' && !book[j]) {
                    book[i] = book[j] = 1;
                    break;
                } else if (a[j] == '[' && !book[j]) break;
            }
        } else if (a[i] == ']') {
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] == '[' && !book[j]) {
                    book[i] = book[j] = 1;
                    break;
                } else if (a[j] == '(' && !book[j]) break;
            }
        }
    }

    for (int i = 0; i < a.length(); i++) {
        if (book[i] == 1) cout << a[i];
        else {
            if (a[i] == ')' || a[i] == '(') cout << "()";
            else if (a[i] == ']' || a[i] == '[') cout << "[]";
        }
    }

    return 0;
}
