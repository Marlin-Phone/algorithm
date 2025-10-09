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

int n, r;
int n1(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n*n1(n - 1);
}
int C(int n, int m){ // n!/(m! * (n - m)!)
    return n1(n)/(n1(m)*n1(n-m));
}

void solve() {
    cin >> n >> r;
    int ans = pow(r, n);
    auto func = [&](int r){
        int sum = 0;
        for(int k = 0; k <= r; k++){
            sum += pow(-1, k) * C(r, k) * pow(r - k, n);
        }
        return sum;
    };
    int temp = func(r);
    cout << temp << endl;
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