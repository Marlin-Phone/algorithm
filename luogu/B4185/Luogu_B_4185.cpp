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

string nums;

void solve() {
    cin >> nums;
    int cnt5 = 0;
    int cnt4 = 0;
    int cnt20 = 0;
    for(int i = 0; i < nums.size(); i++){
        int num = nums[i] - '0';
        if(num == 0 || num == 5){
            cnt5 += i + 1;
        }
    }
    
    for(int i = 0; i < nums.size(); i++){
        int d = nums[i] - '0';
        if(d % 4 == 0){
            cnt4++;
        }
    }
    for(int i = 1; i < nums.size(); i++){
        int num = (nums[i - 1] - '0') * 10 + (nums[i] - '0');
        if(num % 4 == 0){
            cnt4 += i;
        }
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == '0'){
            cnt20++;
        }
    }
    for(int i = 1; i < nums.size(); i++){
        int num = (nums[i - 1] - '0') * 10 + (nums[i] - '0');
        if(num % 20 == 0){
            cnt20 += i;
        }
    }

    int ans = cnt4 + cnt5 - cnt20;
    cout << ans << endl;
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