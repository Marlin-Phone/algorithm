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
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

const int MAX_LEN = 5e3;
int n;
int cnt[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        cnt[num]++;
    }
    int ans = 0;
    for (int z = 1; z <= MAX_LEN; z++) {
        if (cnt[z] < 2) {
            continue;
        }

        int pairs = 0;
        for (int x = 1; x <= z / 2; x++) {
            int y = z - x;
            if (y > MAX_LEN) {
                continue;
            }
            if (x == y) {
                pairs =
                    mod(pairs + cnt[x] * (cnt[x] - 1) / 2); // 即为 C(cnt[x], 2)
            } else {
                pairs =
                    mod(pairs +
                        cnt[x] * cnt[y]); // 即为 C(cnt[x], 1) + C(cnt[y], 1);
            }
        }
        int ways_z = cnt[z] * (cnt[z] - 1) / 2;
        ans = mod(ans + pairs * ways_z); // 拼接方案数*选z方案数
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