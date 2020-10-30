#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n = 0;
        string a;
        cin >> n >> a;

        if (n == 1) {
            if ((a[0] - '0') % 2 == 0) cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }

        int book[5005];
        memset(book, 0, sizeof(book));
        for (int k = n / 2; k > 0; k--) {
            int flaga = 0, flagb = 0;

            for (int i = 1; i <= n; i += 2) { // 奇数位
                if ((a[i - 1] - '0') % 2 == 0) { // 尽量去掉偶数
                    if (book[i] == 0) {
                        book[i] = 1; // 去掉
                        flaga = 1;
                        break;
                    }
                }
            }

            if (!flaga) {
                // 如果没有则随便去掉一个
                for (int i = 1; i <= n; i += 2) { // 奇数位
                    if (book[i] == 0) {
                        book[i] = 1;
                        break;
                    }
                }
            }

            if (n % 2 == 0 && k == 1) break; // 如果是偶数位则留下一位判断
            for (int i = 2; i <= n; i += 2) { // 偶数位
                if ((a[i - 1] - '0') % 2 == 1) { // 尽量去掉奇数
                    if (book[i] == 0) {
                        book[i] = 1; // 去掉
                        flagb = 1;
                        break;
                    }
                }
            }

            if (!flagb) {
                // 如果没有则随便去掉一个
                for (int i = 2; i <= n; i += 2) { // 偶数位
                    if (book[i] == 0) {
                        book[i] = 1;
                        break;
                    }
                }
            }
        }

        // 查询结果
        for (int i = 1; i <= n; i++) {
            if (book[i] == 0) {
                if ((a[i - 1] - '0') % 2 == 0) {
                    cout << 2 << endl;
                } else {
                    cout << 1 << endl;
                }

                break;
            }
        }
    }

    return 0;
}
