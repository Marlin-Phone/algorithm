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
int ans = 0;

int f(int num){
    int res = 0;
    while(num){
        int tmp = num % 10;
        num /= 10;
        res += tmp;
    }
    return res;
}

// int dfs(int n){
//     if(n == 0){
//         return 1;
//     }
//     return ans + f(dfs(n - 1));
// }

void solve() {
    cin >> n;
    // dfs(n);
    vector<int> A(n + 1);
    A[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            A[i] += f(A[j]);
        }
    }
    cout << A[n] << endl;
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