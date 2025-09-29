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

int m1, m2;
int n;
int nums[N];

vector<pair<int, int>> factorize(int n){
    vector<pair<int, int>> res;
    auto push = [&](int p){
        int cnt = 0;
        while(n % p == 0){
            n /= p;
            cnt++;
        }
        if(cnt) {
            res.emplace_back(p, cnt);
        }
    };
    push(2);
    for(int p = 3; p * p <= n; p += 2) push(p);
    if(n > 1){
        res.emplace_back(n, 1);
    }
    return res;
}

void solve() {
    int ans = 1e9;
    cin >> n;
    int m1, m2;
    cin >> m1 >> m2;
    map<int, int> tar;
    vector<pair<int, int>> temp = factorize(m1);
    
    // for(auto it : temp){
    //     dbg(it.first);
    //     dbg(it.second);
    // }

    // dbg(m2);
    for(auto &it : temp){
        tar[it.first] = it.second * m2;
        // dbg(tar[it.first]);
    }


    for(int i = 1; i <= n; i++){ // 遍历每一个num
        cin >> nums[i];
    }
    if(m1 == 1){
        cout << 0 << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        int max_num = -1;
        // dbg(nums[i]);
        vector<pair<int, int>> temp = factorize(nums[i]);
        map<int, int> temp_mp;
        for(auto &it : temp){
            temp_mp[it.first] = it.second;
        }
        // for(auto &it : temp){
        //     dbg(it.first);
        //     dbg(it.second);
        //     cout << endl;
        // }
        for(auto &[a, b] : tar){
            if(temp_mp[a]){
                int tmp = (tar[a] + temp_mp[a] - 1)/ temp_mp[a];
                // dbg(tmp);
                max_num = max(max_num, tmp);
            }else{
                max_num = -1;
                break;
            }
        }
        // dbg(max_num);
        ans = max_num == -1 ? ans : min(ans, max_num);
    }
    
    cout << (ans == 1e9 ? -1 : ans) << endl;
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