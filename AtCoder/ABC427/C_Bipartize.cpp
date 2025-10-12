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
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    int ans = 0;
    for(int i = 0; i < (1 << n); i++){ // 枚举所有染色方案
        int val = 0;
        for(auto &[u, v] : edges){
            int c_u = (i >> u) & 1;
            int c_v = (i >> v) & 1;
            if(c_u != c_v){
                val++;
            }
        }
        ans = max(ans, val);
    }

    cout << m - ans << endl;
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