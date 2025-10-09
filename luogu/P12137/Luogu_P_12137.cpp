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
// const int N = 1e6 + 10;

int n;
int ans = 0;
int sum = 0;

int ksm(int x, int n){
    int res = 1;
    while(n){
        if(n & 1){
            res = mod(res * x);
        }
        n >>= 1;
        x = mod(x * x);
    }
    return res;
}

void solve() {
    cin >> n;
    vector<int> arr(n + 10, 0);
    vector<int> S(n + 10, 0);
    vector<int> pow3(n + 10, 0);
    pow3[0] = 1;
    for(int i = 1; i <= n; i++){
        pow3[i] = mod(pow3[i - 1] * 3);
    }
    // dbg(ksm(2, 10));
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        S[i] = S[i - 1] ^ arr[i];
        int w = 0;
        if(i == n){
            w = 1;
        }else{
            w = mod(2 * pow3[n - 1 - i]);
        }
        // dbg(w);
        ans = mod(ans + S[i] * w);
    }
    cout << ans << endl;
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