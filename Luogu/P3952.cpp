/* P3952 时间复杂度
 * 来源: NOIP 2017
 * 作者: RainbowBird
 * 日期: 2020-10-27
 * 算法: 模拟
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

//#define DEBUG

int T;

struct Line {
    char op, i;
    int x, y;
    bool disable;
};

int main() {
    #ifdef DEBUG
    freopen("P3952.in", "r", stdin);
    #endif

    cin >> T;
    while (T--) {
        int L, reqO = 0, resO = 0;
        string O;
        cin >> L >> O;
        if (O != "O(1)")
            sscanf(O.c_str(), "O(n^%d)", &reqO);

        vector<Line> que;
        for (int i = 1; i <= L; i++) {
            char op;
            cin >> op;
            if (op == 'F') {
                char i;
                string tmp1, tmp2;
                cin >> i >> tmp1 >> tmp2;
                int x = (tmp1 == "n" ? 101 : stoi(tmp1));
                int y = (tmp2 == "n" ? 101 : stoi(tmp2));
                que.push_back(Line{'F', i, x, y, 0});
            } else if (op == 'E') {
                que.push_back(Line{'E', 0, 0, 0, 0});
            }
        }

        int err = 0, tmpO = 0;
        map<char, bool> var;
        stack<char> op;
        Line nowLine, lastLine = {'F', 0, 0, 101, 0};
        for (auto k = que.begin(); k != que.end(); k++) {
            nowLine = *k;

            if (nowLine.op == 'F') {
                op.push('F');

                if (!var[nowLine.i]) var[nowLine.i] = 1;
                else { err = 1; break; }

                if (!nowLine.disable) {
                    if (nowLine.x <= nowLine.y) {
                        if (nowLine.y == 101 && nowLine.x != 101) {
                            stack<char> st;
                            st.push('F');
                            auto p = k + 1;
                            tmpO++;
                            while (!st.empty() && p != que.end()) {
                                if (p->op == 'E') {
                                    resO = max(resO, tmpO);
                                    st.pop();
                                    tmpO--;
                                } else {
                                    st.push('F');
                                    if (p->x > p->y) break;
                                    if (p->y == 101 && p->x != 101) tmpO++;
                                    p->disable = 1;
                                }
                                p++;
                            }

                            resO = max(resO, tmpO);
                            tmpO = 0;
                        }
                    } else {
                        nowLine.disable = 1;
                        stack<char> st;
                        st.push('F');
                        for (auto p = k; p != que.end(); p++) {
                            if (st.empty()) break;
                            if (p->op == 'F') {
                                st.push('F');
                                p->disable = 1;
                            } else if (st.top() == 'F') {
                                st.pop();
                            }
                        }
                    }
                }
            } else {
                if (op.empty()) { err = 1; break; }
                if (op.top() == 'F') op.pop();
                for (auto p = k; p >= que.begin(); p--) {
                    if (p->op == 'F' && var[p->i]) var[p->i] = 0;
                }
            }

            lastLine = nowLine;
        }

        if (err || !op.empty()) {
            cout << "ERR" << endl;
        } else if (resO == reqO) {
            cout << "Yes" << endl;
        } else {
            #ifdef DEBUG
            cout << "No: " << resO << endl;
            #else
            cout << "No" << endl;
            #endif
        }
    }

    return 0;
}
