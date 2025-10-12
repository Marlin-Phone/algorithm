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
int a[N];
int c[N];
int b[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    int next = 1;
    for(int i = 1; i <= n; i++){
        int diff = b[i] - b[i - 1];
        int tmp = i - diff;
        // dbg(diff);
        // dbg(tmp);
        if(tmp == 0){
            a[i] = next;
            next++;
        }else{
            a[i] = a[tmp];
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

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