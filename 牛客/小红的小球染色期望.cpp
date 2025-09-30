#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int n;

void solve() {
    cin >> n;
    if(n <= 1){
        cout << 0 << endl;
        return;
    }

    vector<int> inv(n + 1);
    inv[1] = 1;
    for(int i = 2; i <= n; i++){
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }

    vector<int> E(n + 1, 0);
    vector<int> S(n + 1, 0);

    for(int i = 2; i <= n; i++){
        int term = (2LL * S[i - 2]) % MOD;
        E[i] = (1 + term * inv[i - 1]) % MOD;
        S[i] = (S[i - 1] + E[i]) % MOD; 
    }

    cout << E[n] << endl;
    return;
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