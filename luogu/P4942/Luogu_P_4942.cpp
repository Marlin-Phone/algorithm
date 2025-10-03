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

int l, r;

void solve() {
    cin >> l >> r;
    // int cnt = (r - l + 1) % 9;
    // int ans = cnt * (l % 9) % 9 + (cnt) * (cnt - 1) % 9 * 5 % 9;
    // cout << ans % 9 << endl;
    cout << (((l + r) % 9) * ((r - l + 1) % 9) * 5) % 9 << endl;

}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}