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
bool f[10010];
// p：当前还剩下多少条直线未被分组
// m：当前已累计的交点数
void suv(int p, int m) {
    // 当 p == 0：所有直线都已分组 → 得到一个完整方案 → 交点数 = m
    //  用布尔数组 f[] 记录该交点数是否出现过 → 首次出现则 ans++
    if (p == 0) {
        if (!f[m]) {
            ans++;
            f[m] = 1;
        }
    } else {
        // p：当前剩余未分组的直线数
        // r：我们这次要选 r 条直线组成一组平行线
        for (int r = p; r >= 1; r--) {
            suv(p - r, r * (p - r) + m); // r * (p - r)为此次分出的r产生的交点数
        }
    }
}

void solve() {
    cin >> n;
    suv(n, 0);
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