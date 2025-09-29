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

int a, b;

int dfs(int a, int b){
    if(a == b){
        return 4 * a;
    }
    if(a == 1){
        return 4 * b;
    }
    if(a == 0){
        return 0;
    }
    return 4 * a * (b / a) + dfs(b % a, a);
}
void solve() {
    int ans = 0;
    cin >> a >> b;
    if(a > b){
        swap(a, b);
    }
    ans = dfs(a, b);
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