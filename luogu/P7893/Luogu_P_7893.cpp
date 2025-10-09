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

int n, p;

void solve() {
    cin >> n >> p;
    if(p == 1){
        cout << 0 << endl;
        return;
    }
    int sum = 0;
    for(int i = 0; n > 0; n = n / p, i++){
        sum += (i % 2 == 0 ? 1 : -1) * n;
    }
    cout << sum << endl;
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