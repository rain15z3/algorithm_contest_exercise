#include <iostream>
#include <cstring>
using namespace std;

int T, n, m;
struct Tang {
    int a, b;
} tang[50005];
int c[50005];

int main() {
    cin >> T;
    while (T--) {
        memset(tang, 0, sizeof(tang));
        memset(c, 0, sizeof(c));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> tang[i].a >> tang[i].b;
        for (int j = 1; j <= m; j++) {
            int a;
            cin >> a;
            c[a] = 1;
        }
        
        // 统计敌人数量
        int enemy[50005], cura = 0, curb = 0;
        for (int i = 1; i <= n; i++) {
            if (tang[i].a == 0) {
                cura++;
                enemy[i] = curb;
            } else if (tang[i].a == 1) {
                curb++;
                enemy[i] = cura;
            }
        }
        
        int diffa[50005], diffb[50005];
        for (int t = 1; t <= n; t++) { // 游戏开始
            // 发功
            diffa[1] += c[t];
            diffa[cura + 1] -= c[t];
            diffb[1] += c[t];
            diffb[curb + 1] -= c[t];
            
            // 攻击
            for (int i = 1; i <= n; i++) {
                if (tang[i].a == 0) {
                    diffb[1] -= tang[i].b;
                    diffb[enemy[i]+1] += tang[i].b;
                } else if (tang[i].a == 1) {
                    diffa[1] -= tang[i].b;
                    diffa[enemy[i]+1] += tang[i].b;
                }
            }
        }
        
        // 前缀和
        int tot = n, adda = 0, addb = 0;

        for (int i = 1; i <= cura; i++) {
            adda += diffa[i];
            tang[enemy[i]+1].b -= adda;
            if (tang[enemy[i]+1].b <= 0) tot--;
        }

        for (int i = 1; i <= curb; i++) {
            addb += diffb[i];
            tang[enemy[i]+1].b -= addb;
            if (tang[enemy[i]+1].b <= 0) tot--;
        }
        
        cout << tot << endl;
    }
    
    return 0;
}
