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
int C[27][27];

void initC() {
    for (int i = 0; i <= 26; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
    }
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    // for (int i = 0; i <= 26; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << C[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
bool is_valid(string s) {
    if (s.size() > 6) {
        return false;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 'a' || s[i] > 'z') {
            return false;
        }
        if (i < s.size() - 1 && s[i] >= s[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    string str;
    cin >> str;
    initC();
    if (!is_valid(str)) {
        cout << 0 << endl;
        return;
    }
    int total = 0;
    int k = str.size();
    for (int i = 1; i < k; i++) {
        total += C[26][i];
    }
    // dbg(total);
    int rank = 0;
    for (int i = 0; i < k; i++) {
        int start = (i == 0) ? 1 : (str[i - 1] - 'a' + 2);
        int end = str[i] - 'a';
        for (int c = start; c <= end; c++) {
            int remain = k - i - 1;
            rank += C[26 - c][remain];
        }
    }
    total += rank + 1;

    cout << total << endl;
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
