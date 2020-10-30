/* P1138 第k小整数
 * https://www.luogu.com.cn/problem/P1138
 * 作者：RainbowBird
 * 日期：2020年7月9日
 * 算法：nth_element
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[10005], b[10005], cur;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[temp]++;
        if (a[temp] == 1)
            b[++cur] = temp;
    }
    
    nth_element(b + 1, b + k, b + 1 + cur);


    if (b[k] == 0)
        cout << "NO RESULT" << endl;
    else
        cout << b[k] << endl;

    return 0;
}
