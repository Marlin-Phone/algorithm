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
// int a[N];


void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 步骤1：统计每种长度的出现次数，并分离“成对”和“单独”
    sort(a.begin(), a.end());
    int sum = 0; // 存所有成对边的总长度
    vector<int> b {0}; // 存放所有单独的边（每种长度保留一个）
    int cnt = 0; // 成对使用的边的总数量

    for(int l = 0, r = 0; l < n; l = r){
        while(r < n && a[l] == a[r]){
            r++;
        }
        // 成对部分，取(r - l) / 2对，每对贡献 2 * a[l]
        sum += (r - l) / 2 * 2 * a[l];
        cnt += (r - l) / 2 * 2;
        // 如果r - l 为奇数，剩下一个单独的
        if((r - l) % 2){
            b.push_back(a[l]);
        }
    }

    // 步骤2：尝试加入一个“单独”的边，形成奇数多边形
    int ans = 0;
    for(int i = 1; i < b.size(); i++){
        if(sum + b[i - 1] > b[i]){ // 检查是否是合法的多边形
            ans = max(ans, (b[i - 1] + b[i])); // 是则加入最大的单个边
        }
    }

    if(cnt > 2 || ans > 0){
        ans += sum;
    }

    cout << ans << endl;
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