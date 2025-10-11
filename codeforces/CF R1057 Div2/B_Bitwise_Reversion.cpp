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

int x, y, z;

void solve() {
    cin >> x >> y >> z;
    // cout << bitset<10>(x) << endl;
    // cout << bitset<10>(y) << endl;
    // cout << bitset<10>(z) << endl;
    if(((x & y) | (x & z) | (y & z)) == (x & y & z)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
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