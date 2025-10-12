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

void solve(){
    cin >> n;
    if (n == 0) {
        cout << "YES" << endl;
        return;
    }
    vector<bool> b;
    while (n) {
        b.push_back(n & 1);
        n >>= 1;
    }
    int cnt = 0;
    while(b[cnt] == false){
        cnt++;
    }
    while (cnt--){
        b.push_back(0);
    }
    int k = b.size();
    bool flag;
    if(k % 2 == 1){
        flag = !b[k / 2];
    }else{
        flag = true;
    }
    for (int i = 0; flag && i < k / 2; i++){
        flag = (b[i] == b[k - 1 - i]);
    }
    if (flag == false) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}


signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t = 1;
    cin >> t; 
    while (t--){
        solve();
    }

    return 0;
}