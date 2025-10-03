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
const int N = 1e3 + 10;

int n, m, k;
int A[N][N], B[N][N], C[N][N];

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= k; j++){
            cin >> B[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int x = 1; x <= k; x++){
            for(int j = 1; j <= m; j++){
                C[i][x] += A[i][j] * B[j][x];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
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