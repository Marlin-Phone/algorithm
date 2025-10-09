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
int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int type, n, m;

void solve() {
    cin >> type >> n >> m >> MOD;
    int start = n - 2 * m + 2;
    int end = n - m + 1;

    int ans = 1 % MOD;
    for(int i = start; i <= end; i++){
        ans = (ans * (i % MOD)) % MOD;
    }
    cout << ans << endl;
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