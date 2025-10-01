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
vector<pair<int, int>> factorize(int n){
    vector<pair<int, int>> res;
    auto push = [&](int p){
        int cnt = 0;
        while(n % p == 0){
            n /= p;
            cnt++;
        }
        if(cnt){
            res.emplace_back(p, cnt);
        }
    };
    push(2);
    for(int i = 3; i * i <= n; i += 2){
        push(i);
    }
    if(n > 1){
        res.emplace_back(n, 1);
    }
    return res;
}
int euler_phi(int n){
    if(n == 1) return 1;
    if(n <= 0) return 0;

    vector<pair<int, int>> factors = factorize(n);
    int result = n;

    for(auto &factor : factors){
        int p = factor.first;
        result = result / p * (p-1);
    }
    return result;
}
int ksm(int x, int n){
    int res = 1;
    while(n){
        if(n & 1){
            res = mod(res * x);
        }
        x = mod(x * x);
        n >>= 1;
    }
    return res;
}

void solve() {
    // cout << euler_phi(2023) << endl;
    cout << ksm(2023, 2022) * euler_phi(2023) % MOD << endl;
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