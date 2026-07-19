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
    int ans = 0;
    cin >> n;
    vector<pair<int, int>> point(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> point[i].first >> point[i].second;
    }

    for (int i = 0; i < n; i++) {         // 分割线点i
        for (int j = i + 1; j < n; j++) { // 分割线点j
            int dx = point[j].first - point[i].first;
            int dy = point[j].second - point[i].second;
            int left = 0, right = 0;
            for (int k = 0; k < n; k++) { // 枚举点k
                if (k == i || k == j) {
                    continue;
                }
                int cross = dx * (point[k].second - point[i].second) -
                            dy * (point[k].first - point[i].first);
                if (cross > 0) {
                    left++;
                } else if (cross < 0) {
                    right++;
                }
            }
            if (left == right) {
                ans++;
            }
        }
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