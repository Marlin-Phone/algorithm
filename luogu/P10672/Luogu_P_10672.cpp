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
map<int, int> cnts;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        cnts[temp]++;
    }
    if(cnts.size() % 2 == 1){
        cout << -1 << endl;
        return;
    }
    for(auto &[num, cnt] : cnts){
        cout << num << " ";
        cnt--;
    }
    for(auto &[num, cnt] : cnts){
        while(cnt--){
            cout << num << " ";
        }
    }
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