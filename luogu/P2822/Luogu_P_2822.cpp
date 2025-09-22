#include <bits/stdc++.h>
using namespace std;

const int N = 2003;
int C[N + 1][N + 1]; // 杨辉三角
int d[N + 1][N + 1]; // 前缀和
int n, m, k;

void solve() {
    cin >> n >> m;
    cout << d[n][min(n, m)] << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t >> k;

    // 预处理组合数 C[i][j] mod k
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
            }
        }
    }

    // 预处理前缀和 d[i][j] = 满足 0<=x<=i, 0<=y<=j 且 y<=x 且 C[x][y]%k==0
    // 的格子数
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            int val = 0;
            if (j <= i) {
                val = (C[i][j] % k == 0);
            }
            int up = (i > 0) ? d[i - 1][j] : 0;
            int left = (j > 0) ? d[i][j - 1] : 0;
            int diag = (i > 0 && j > 0) ? d[i - 1][j - 1] : 0;
            d[i][j] = up + left - diag + val;
        }
    }

    while (t--) {
        solve();
    }

    return 0;
}