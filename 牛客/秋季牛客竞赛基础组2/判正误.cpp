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
const ll LIM = 3'000'000'000LL;


int a, b, c, d, e, f, g;

int calc(int x, int n){
    if(n == 0) return 1;
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x == -1) return (n % 2 == 1 ? -1 : 1);

    if(abs(x) > 1 && n > 60){
        return (x > 0) ? LIM + 1 : -(LIM + 1);
    }

    int res = 1;
    for(int i = 0; i < n; i++){
        if(res > LIM || res < -LIM) break;
        res *= x;
    }
    return res;
}

void solve() {
    cin >> a >> b >> c >> d >> e >> f >> g;
    int A = calc(a, d);
    int B = calc(b, e);
    int C = calc(c, f);
    
    if(abs(A) > LIM || abs(B) > LIM || abs(C) > LIM){
        cout << "No" << endl;
        return;
    }

    if(A + B + C == g){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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