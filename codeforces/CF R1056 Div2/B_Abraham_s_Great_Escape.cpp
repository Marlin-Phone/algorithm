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

int n, k;
int tar;


void solve() {
    cin >> n >> k;
    vector<vector<char>> g(n + 1, vector<char> (n + 1));
    if(k == n * n - 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    tar = n * n - k;
    int flag = false;
    for(int i = 1; i <= n && !flag; i++){
        for(int j = 1; j <= n && !flag; j++){
            if(tar == 0){
                flag = true;
                continue;
            }
            if(i == 1){
                if(i == 1 && j == 1){
                    g[i][j] = 'R';
                }else if(i == 1 && j == 2){
                    g[i][j] = 'L';
                }else{
                    g[i][j] = 'L';
                }
            }else{
                // dbg(j);
                if(j == 1){
                    g[i][j] = 'U';
                }else{
                    g[i][j] = 'L';
                }
            }
            tar--;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(g[i][j] == 'L' || g[i][j] == 'R' || g[i][j] == 'U'){
                cout << g[i][j];
            }else{
                cout << 'D';
            }
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