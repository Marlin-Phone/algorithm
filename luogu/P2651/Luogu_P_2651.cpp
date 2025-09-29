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

int n;
int arr[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    if(n == 1){
        cout << "Yes" << endl;
        return;
    }else if(n == 2){
        if(arr[1] % arr[2] == 0){
            cout << "Yes" << endl;
            return;
        }else{
            cout << "No" << endl;
            return;
        }
    }
    int fz = arr[1];
    int fm = arr[2];
    fm /= __gcd(fm, fz);
    for(int i = 3; i <= n; i++){
        fm = fm / __gcd(fm, arr[i]);
        // dbg(__gcd(fm, arr[i]));
        // dbg(fm);
    }
    if(fm == 1){
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