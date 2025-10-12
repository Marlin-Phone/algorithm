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

void solve() {
    cin >> n;
    vector<int> vec(n + 1);
    set<int> a;
    for(int i = 1; i <= n; i++){
        cin >> vec[i];
        a.insert(vec[i]);
    }

    // for(auto it : a){
    //     dbg(it);
    // }

    int x = 0;
    while(1){
        if(a.count(x) == 0){
            bool flag = true;
            for(int i = 0; i < x; i++){
                if(a.count(i) == 0){
                    flag = true;
                    break;
                }
            }
            if(flag){
                // dbg(x);
                cout << x << endl;
                break;
            }
        }
        // dbg(x);
        x++;
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