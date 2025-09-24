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

int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    bool inc = true;
    for (int i = 1; i < m; i++) {
        if (a[i] != a[i - 1] + 1) {
            inc = false;
            break;
        }
    }

    if (inc) {
        int start = a[0];
        int need = start + m - 1;
        if (need > n) {
            cout << 0 << endl;
        } else {
            cout << n - need + 1 << endl;
        }
    } else {
        int mx = *max_element(a.begin(), a.end());
        int k0 = a[0];
        int k1 = min(n, mx + m);
        int cnt = 0;

        for (int k = k0; k <= k1; k++) {
            if (a[0] > k) {
                continue;
            }
            int blk = k;
            int pos = a[0];
            bool ok = true;

            for (int i = 0; i < m; i++) {
                if (pos > blk) {
                    blk++;
                    pos = 1;
                    if (blk > n) {
                        ok = false;
                        break;
                    }
                }
                if (pos != a[i]) {
                    ok = false;
                    break;
                }
                pos++;
            }

            if (ok) {
                cnt++;
            }
        }
        cout << cnt << endl;
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