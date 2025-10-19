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

void solve() {
    cin >> n >> k;
    int ans = 0;
    string str = " ";
    string tmp;
    cin >> tmp;
    str += tmp;
    // dbg(tmp);
    
    int l = 1, r = 1;
    int cnt1 = 0;
    while(r <= n){
        while(r - l + 1 <= k && r <= n){
            // dbg(str[r]);
            cnt1 += str[r] - '0'; 
            if(str[r] == '1'){
                // dbg(cnt1);
                if(cnt1 == 1){
                    ans++;
                }
            }
            r++;
        }
        cnt1 -= str[l] - '0';
        l++;
    }
    cout << ans << endl;
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