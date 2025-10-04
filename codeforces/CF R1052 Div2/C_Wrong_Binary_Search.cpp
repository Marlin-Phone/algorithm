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
string str;

void solve() {
    cin >> n;
    cin >> str;
    vector<int> xs;
    for(int i = 0; i < n; i++){
        if(str[i] == '1'){
            xs.push_back(i + 1);
        }
    }
    if(xs.empty()){
        cout << "YES" << endl;
        for(int i = n; i >= 1; i--){
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    int min_x = *min_element(xs.begin(), xs.end());
    int max_x = *max_element(xs.begin(), xs.end());
    if(xs.size() != max_x - min_x + 1){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<int> p(n + 1);

    for(int x = min_x; x <= max_x; x++){
        p[x] = x;
    }

    vector<int> left_nums;
    for(int x = 1; x < min_x; x++){
        left_nums.push_back(x);
    }
    reverse(left_nums.begin(), left_nums.end());
    for(int  i = 0; i < left_nums.size(); i++){
        p[i + 1] = left_nums[i];
    }

    vector<int> right_nums;
    for(int x = max_x + 1; x <= n; x++){
        right_nums.push_back(x);
    }
    reverse(right_nums.begin(), right_nums.end());
    int right_start = max_x + 1;
    for(int i = 0; i < right_nums.size(); i++){
        p[right_start + i] = right_nums[i];
    }

    for(int i = 1; i <= n; i++){
        cout << p[i] << " ";
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