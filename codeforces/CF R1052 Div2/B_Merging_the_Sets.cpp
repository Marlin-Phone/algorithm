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

int n, m;

void solve() {
    cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    vector<vector<int>> vec;
    for(int i = 1; i <= n; i++){
        int S_n;
        cin >> S_n;
        vector<int> arr;
        for(int j = 1; j <= S_n; j++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        vec.push_back(arr);
    }
    for(auto its : vec){
        for(auto it : its){
            cnt[it]++;
        }
    }
    int min_cnt = *min_element(cnt.begin() + 1, cnt.begin() + 1 + m);
    // case1: 0次
    if(min_cnt == 0){
        cout << "NO" << endl;
        return;
    }
    
    vector<bool> is_must(n + 1, false);
    for(int i = 0; i < n; i++){
        for(int x : vec[i]){
            if(cnt[x] == 1){
                is_must[i] = true;
                break;
            }
        }
    }

    vector<bool> must_cover(m + 1, false);
    int must_count = 0;
    for(int i = 0; i < n; i++){
        if(is_must[i]){
            must_count++;
            for(int x : vec[i]){
                must_cover[x] = true;
            }
        }
    }

    bool full = true;
    for(int x = 1; x <= m; x++){
        if(!must_cover[x]){
            full = false;
            break;
        }
    }

    if(full){
        int temp = n - must_count;
        if(temp >= 2){
            cout << "YES" << endl;
            return;
        }else{
            cout << "NO" << endl;
            return;
        }
    }else{
        cout << "YES" << endl;
        return;
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