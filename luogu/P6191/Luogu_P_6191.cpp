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
const int MOD = 5000011;
// const int N = 1e6 + 10;

int n, k; // 1e5

void solve() {
    cin >> n >> k;
    vector<int> dp(n + 1);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        // 第i个位置放奶牛
        dp[i] = dp[i - 1];
        
        // 第i个位置放公牛
        int prev = i - k - 1;
        if (prev >= 0) {
            dp[i] = (dp[i] + dp[prev]) % MOD;
        } else {
            dp[i] = (dp[i] + 1) % MOD;
        }
    }
    
    cout << dp[n] << endl;
    
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