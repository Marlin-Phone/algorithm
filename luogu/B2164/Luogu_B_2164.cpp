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
const int MOD = 1e9 + 7;
const int N = 5e3 + 10;

int n, m;
int C[N][N];

void init(int a, int b){
    int n = max(a, b);
    for(int i = 0; i <= n; i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = mod(C[i - 1][j - 1] + C[i - 1][j]);
        }
    }
}

void solve() {
    cin >> n >> m;
    init(n, m);
    cout << C[n][m] << endl;
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