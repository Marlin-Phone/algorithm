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
const int MOD = 998244353;
// const int N = 1e6 + 10;

int n, k;
int ksm(int x, int n){
    int res = 1;
    while(n){
        if(n & 1){
            res = mod(res * x);
        }
        n >>= 1;
        x = mod(x * x);
    }
    return res;
}
void solve() {
    cin >> n >> k;
    cout << ksm(ksm(2, k) - 1, n) << endl;
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