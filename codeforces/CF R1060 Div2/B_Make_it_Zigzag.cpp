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
const int N = 1e6 + 10;

int n, m;
int a[N];

void solve() {
    cin >> n;
    int ans = 0;
    int preMax = -1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        preMax = max(preMax, a[i]);
        if(i % 2 == 0){
            a[i] = preMax;
        }
    }
    // for(int i =  1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for(int i = 1; i <= n; i++){
        if(i % 2 == 1){
            if(i == 1){
                if(a[i] >= a[i + 1]){
                    int tmp = a[i] - (a[i + 1] - 1);
                    ans += tmp;
                    // dbg(tmp);
                    // ai = a[i + 1] - 1
                }
            }else if(i == n){
                if(a[i] >= a[i - 1]){
                    int tmp = a[i] - (a[i - 1] - 1);
                    ans += tmp;
                    // dbg(tmp);
                }
            }else{
                if(a[i] >= min(a[i - 1], a[i + 1])){
                    int tmp = a[i] - min(a[i - 1] - 1, a[i + 1] - 1);
                    // dbg(tmp);
                    ans += tmp;
                }
            }
        }
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