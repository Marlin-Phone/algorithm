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
    string s, t;
    cin >> s;
    cin >> t;
    char c = '2';

    vector<int> need1, need0;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            continue;
        } else {
            if (s[i] == '0') {
                need1.push_back(i + 1);
            } else {
                need0.push_back(i + 1);
            }
        }
    }

    int m = need0.size();
    if (m == 0) {
        cout << 0 << endl;
        return;
    } else {
        cout << 2 * m + 1 << endl;
    }

    cout << need0[0] << endl;

    for (int i = 0; i < m; i++) {
        cout << need1[i] << endl;
        if (i < m - 1) {
            cout << need0[i + 1] << endl;
        } else {
            cout << need0[0] << endl;
        }
    }
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