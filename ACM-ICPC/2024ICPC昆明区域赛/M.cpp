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
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 0){
                int x = i, y = j; 
                while(x >= 1 && x <= n && y >= 1 && y <= m){
                    a[x][y] = cnt++;
                    x += 1;
                    y -= 1;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
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