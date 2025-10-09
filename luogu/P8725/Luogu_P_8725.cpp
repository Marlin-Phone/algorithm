#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Math
#define mod(x) ((x + MOD) % MOD)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const double eps = 1e-8;
const int MOD = 1e9 + 7;
const int N = 3e3 + 10;

int D, T, M;
int dp[N][N]; // 时间t, 体力m
// (M - m): 向上游的次数
// t - (M - m): 向下流的次数
// d = D + 2* (M - m) - t; 
// dp[t][m] = dp[t - 1][m] + (M < m) ? dp[t - 1][M + 1] : 0;
void solve() {
    cin >> D >> T >> M;
    dp[0][M] = 1;
    
    // 填充DP表
    for (int t = 1; t <= T; t++) {
        for (int m = 0; m <= M; m++) {
            // 计算当前位置
            int position = t - 2 * M + 2 * m;
            
            // 如果当前位置已经死亡（>= D），跳过
            if (position >= D) {
                dp[t][m] = 0;
                continue;
            }
            
            // 方案1：这一秒不划桨（体力不变）
            dp[t][m] = dp[t-1][m];
            
            // 方案2：这一秒划桨（消耗1体力，所以上一秒体力是m+1）
            if (m + 1 <= M) {
                dp[t][m] = (dp[t][m] + dp[t-1][m+1]) % MOD;
            }
        }
    }
    
    // 答案：第T秒结束时，体力用完（剩余0）的方案数
    cout << dp[T][0] << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}