/* P1098 字符串的展开
 * https://www.luogu.com.cn/problem/P1098
 * 作者：RainbowBird
 * 日期：2020年7月10日
 * 算法：字符串
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int p1, p2, p3;
    string str;
    cin >> p1 >> p2 >> p3;
    cin >> str;

    for (size_t k = 0; k < str.length(); k++) {
        if (str[k] == '-' && (k == 0 || k == str.length() - 1))
            continue;

        if (str[k] == '-' && str[k - 1] == '-')
            continue;

        if (str[k - 1] >= str[k + 1])
            continue;

        if (((str[k - 1] >= '0' && str[k - 1] <= '9') && (str[k + 1] < '0' || str[k + 1] > '9')) ||
            ((str[k - 1] >= 'a' && str[k - 1] <= 'z') && (str[k + 1] < 'a' || str[k + 1] > 'z')) ||
            ((str[k - 1] >= 'A' && str[k - 1] <= 'Z') && (str[k + 1] < 'A' || str[k + 1] > 'Z')))
            continue;

        if (str[k] == '-') {
            string temp = "";
            char l = str[k - 1], r = str[k + 1];

            if (l + 1 != r) {
                l += 1, r -= 1;

                if (p1 == 2) {
                    if (l < '0' || l > '9')
                        l -= 32, r -= 32;
                } else if (p1 == 3) {
                    l = r = '*';
                }

                for (char i = l; i <= r; i++) {
                    for (int j = 1; j <= p2; j++) {
                        temp += i;
                    }
                }

                if (p3 == 2)
                    reverse(temp.begin(), temp.end());

                if (temp != "")
                    str.replace(str.begin() + k, str.begin() + k + 1, temp);
            } else {
                str.erase(str.begin() + k, str.begin() + k + 1);
            }
        }
    }

    cout << str << endl;

    return 0;
}