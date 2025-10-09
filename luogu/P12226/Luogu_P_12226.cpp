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

int n, a, b, c;
ll __lcm(ll a, ll b, ll n) {
    if (a == 0 || b == 0) return 0;
    ll g = __gcd(a, b);
    if (b > n || a / g > n / b) {
        return n + 1;
    }
    return (a / g) * b;
}

void solve() {
    cin >> n >> a >> b >> c;
    int A = n / a;
    int AB = n / __lcm(a, b, n);
    int C = n / c;
    int AC = n / __lcm(a, c, n);
    int ABC = n / __lcm(a, __lcm(b, c, n), n);
    int ans = A - AB + C - AC + ABC;
    cout << ans << endl;
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