#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mod(x) ((x + MOD) % MOD)
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl

const int MOD = 1e9 + 7;


void solved(){
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> dp(w + 1, 0);
    dp[0] = 1;
    for(auto v : a){
        // dbg(v);
        for(int j = v; j <= w; j++){
            dp[j] = mod(dp[j] + dp[j - v]);
            // dbg(j);
            // dbg(dp[j]);
        }
        // cout << endl;
    }
    cout << dp[w] << endl;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solved();
    }

    return 0;
}