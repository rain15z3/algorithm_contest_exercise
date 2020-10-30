#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        priority_queue<int, vector<int>, greater<int> > que;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            que.push(a);
        }

        int tot = 0;
        while (1) {
            int a = que.top(); que.pop();
            int b = que.top(); que.pop();

            //cout << "[a: " << a << "][b: " << b << "]" << endl;
            
            int c = a + b;
            if (c > k) break;
            
            que.push(a);
            que.push(c);
            tot++;
        }

        cout << tot << endl;
    }

    return 0;
}
