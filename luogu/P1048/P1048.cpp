#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mod(x) ((x + MOD) % MOD)
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

void solved(){
    int T, M;
    cin >> T >> M;
    vector<int> dp(T + 1, 0);
    
    vector<int> time(M + 1), value(M + 1);
    // t为时间，v为价值

    for(int i = 1; i <= M; i++){
        cin >> time[i] >> value[i];
    }
    for(int i = 1; i <= M; i++){
        for(int j = T; j >= time[i]; j--){
            dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
            // dbg(j);
            // dbg(dp[j]);
        }
    }
    cout << dp[T] << endl;
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