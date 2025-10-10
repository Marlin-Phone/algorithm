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
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int n;

void solve() {
    cin >> n;
    vector<int> dp(n + 10);
    dp[0] = 1;  // 和为0有一种方案：什么都不选
    for(int i = 1; i <= n; i++){        // 遍历每个可选的数字 i
        for(int j = n; j >= i; j--){    // 0-1背包的倒序更新
            dp[j] += dp[j - i];        // 考虑选或不选数字 i
        }
    }
    cout << dp[n] - 1;
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