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
    vector<pair<int, int>> point;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }
    for(int i = 0; i < n; i++){
        int x1 = point[i].x, y1 = point[i].y;
        for(int j = i + 1; j < n; j++){
            int x2 = point[j].x, y2 = point[j].y;
            for(int k = j + 1; k < n; k++){
                int x3 = point[k].x, y3 = point[k].y;
                // check(x1, y1, x2, y2, x3, y3);
                
            }
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