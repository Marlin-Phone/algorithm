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
int ans = 0;

bool check(string &a){
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    for(auto it : a){
        if(it - '0' == 1){
            flag1++;
        }
        if(it - '0' == 2){
            flag2++;
        }
        if(it - '0' == 3){
            flag3++;
        }
    }

    return (flag1 >= 1 && flag2 >= 1 && flag3 >= 1 && flag1 == flag2 && flag2 == flag3);
}

void solve() {
    cin >> n;
    string a;
    cin >> a;
    for(int i = 0; i < n; i++){
        int cnt[4] = {0};
        for(int j = i; j < n; j++){
            char c = a[j];
            if(c >= '1' && c <= '3'){
                cnt[c - '0']++;
            }
            if(cnt[1] >= 1 && cnt[2] >= 1 && cnt[3] >= 1 && cnt[1] == cnt[2] && cnt[2] == cnt[3]){
                ans++;
            }
        }
    }
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