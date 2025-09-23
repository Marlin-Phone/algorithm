#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
//                      "fast-math")
using namespace std;

// Types
#define ll __int128_t
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

long long n, a, b;
int C[110][110];
int ans = 0;

void init() {
    for (int i = 0; i <= 100; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    // for (int i = 0; i <= 100; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << C[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
void print_int128(unsigned __int128 a) {
    if (a > 9)
        print_int128(a / 10);
    cout << (char)('0' + a % 10);
}
void solve() {
    cin >> n >> a >> b;
    init();
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            ans += C[n + i - 1][n - 1] * C[n + j - 1][n - 1];
        }
    }
    // cout << ans << endl;
    print_int128(ans);
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