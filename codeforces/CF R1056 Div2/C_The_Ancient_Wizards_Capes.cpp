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
const int MOD = 676767677;
const int N = 1e6 + 10;

int n;
int a[N], b[N], c[N], l[N], r[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << "2" << endl;
        return;
    }
    int ans = 0, flag = 1;
    for(int i = 1; i <= n - 1; i++){
        b[i] = a[i + 1] - a[i] + 1;
        if(b[i] < 0 || b[i] > 2){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        cout << 0 << endl;
        return;
    }
    for(int st = 0; st <= 1; st++){
        c[1] = st;
        for(int i = 1; i <= n - 1; i++){
            c[i + 1] = b[i] - c[i];
        }
        for(int i = 1; i <= n; i++){
            l[i] = l[i - 1] + (c[i] == 1);
        }
        r[n + 1] = 0;
        for(int i = n; i >= 1; i--){
            r[i] = r[i + 1] + (c[i] == 0);
        }
        int flag = 1;
        for(int i = 1; i <= n; i++){
            if(l[i] + r[i] != a[i]){
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << endl;
    // 左斗篷记为1，右斗篷记为0
    // 当前人为ci
    // 前缀1 Li 后缀0 Ri
    // ai = Li + Ri i不用管，只会到左右一边
    
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