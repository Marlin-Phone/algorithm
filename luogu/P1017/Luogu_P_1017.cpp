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

int n, r;

void zhuan(int n, int r) { // 题解递归形式
    if (n == 0) {
        return;
    }
    int m = n % r; // m 为余数
    if (m < 0) {   // 如果余数小于0，转化为整数
        m -= r;
        n += r;
    }
    if (m >= 10) { // 将余数转化
        m = 'A' + m - 10;
    } else {
        m += '0';
    }

    zhuan(n / r, r); // 递归的求每一位的余数

    cout << (char)m;
    return;
}
string ten2r(int n, int r) { // 迭代形式
    string res;
    while (n != 0) {
        int m = n % r;
        n /= r;
        if (m < 0) {
            m -= r;
            n++; // 商直接+1，与递归不同（思路相同）
        }
        if (m >= 10) {
            res.push_back('A' + m - 10);
        } else {
            res.push_back('0' + m);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
void solve() {
    cin >> n >> r;
    string ans = "";
    cout << n << "=";
    // zhuan(n, r);
    cout << ten2r(n, r);
    cout << "(base" << r << ")" << endl;
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