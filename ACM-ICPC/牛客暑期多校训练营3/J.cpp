#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
// const int N = 1e6 + 10;

int x, y;

void zhengjie(){
    int sum = (x + y);
    int g = __gcd(x, y);
    cout << sum / g << endl;
}

void solve() {
    cin >> x >> y;
    // if(x == y){
    //     cout << 1 << endl;
    // }
    // if(x)
    if(x == y){
        cout << 1 << endl;
        return;
    }
    if(x > y){
        swap(x, y);
    }
    

    int sum = x + y;
    
    if(sum % 2 == 1){
        cout << -1 << endl;
        return;
    }
    
    int x0 = x;
    // int
    int cnt = -1;
    for(int i = 1; i <= 50; i++){
        // dbg(x0);
        if(x == 0 || y == 0){
            cnt = i - 1;
            break;
        }
        if(x <= y){
            y -= x;
            x += x;
        }else{
            x -= y;
            y += y;
        }
    }
    cout << cnt << endl;
    // if(y % x != 0){
    //     cout << -1 << endl;
    //     return;
    // }else{
    //     cout << y / x << endl;
    //     return;
    // }


}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // zhengjie();
    }

    return 0;
}