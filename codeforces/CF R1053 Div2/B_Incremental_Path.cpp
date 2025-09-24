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

void solve() {
    int n, m;
    set<int> st;
    string str;

    cin >> n >> m;
    cin >> str;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    int pos = 1;
    for (int i = 0; i < n; i++) {
        pos = 1;
        for (int j = 0; j <= i; j++) {
            if (str[j] == 'A') {
                pos++;
            } else {
                pos++;
                // dbg(pos);
                while (st.count(pos)) {
                    pos++;
                }
            }
        }
        st.insert(pos);
    }
    cout << st.size() << endl;
    for (auto it : st) {
        cout << it << " ";
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