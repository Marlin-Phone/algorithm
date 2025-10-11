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
const int MOD = 6662333;
const int N = 1e3 + 10;

int n;
int C[N][N];

int ksm(int x, int n){
    int res = 1;
    while(n){
        if(n & 1){
            res = mod(res * x);
        }
        x = mod(x * x);
        n >>= 1;
    }
    return res;
}

void init(){
    for(int i = 0; i <= n; i++){
        C[0][i] = C[i][i] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

void solve() {
    cin >> n;
    // init();
    cout << ksm(2, n - 1) << endl;
    // int ans = 0;
    // for(int i = 0; i <= n; i += 2){
    //     ans += C[n][i];
    // }
    // cout << ans << endl;
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