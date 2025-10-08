#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int ksm(int x, int n){
    int res = 1;
    while(n){
        if(n & 1){
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD; 
        n >>= 1;
    }
    return res;
}

void solved(){
    int cnt = 10000; // 0 - 3 - 7 + 3 7
    int ans = ksm(9, 10000);
    // cout << ans << endl;
    ans = (ans - ksm(8, 10000) + MOD) % MOD;
    ans = (ans - ksm(8, 10000) + MOD) % MOD;
    ans = (ans + ksm(7, 10000)) % MOD;
    cout << ans << endl;
}
signed main(){
    int t = 1;
    cin >> t;
    while(t--){
        solved();
    }

    return 0;
}
