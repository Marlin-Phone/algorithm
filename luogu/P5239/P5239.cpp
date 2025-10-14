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
const int MOD = 19260817;
// const int N = 1e6 + 10;

int n, m;
// n, m:1e3         q:1e4

vector<vector<int>> C(1010, vector<int>(1010));
vector<vector<int>> S1(1010, vector<int>(1010));
vector<vector<int>> S(1010, vector<int>(1010));

void init(){
    C[0][0] = 1;
    for(int i = 1; i <= 1005; i++){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = mod(C[i - 1][j] + C[i - 1][j - 1]);
        }
    }
    for(int i = 1; i <= 1005; i++){
        for(int j = 1; j <= i; j++){
            S1[i][j] = mod(S1[i][j] + S1[i - 1][j] + C[i][j]);
        }
    }
    for(int i = 1; i <= 1005; i++){
        for(int j = 1; j <= i; j++){
            S[i][j] = mod(S[i][j] + S[i][j - 1] + S1[i][j]);
        }
    }
}

void solve() {
    cin >> m >> n;
    if(m > n){
        cout << S[n][n] << endl;
    }else{
        cout << S[n][m] << endl;
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}