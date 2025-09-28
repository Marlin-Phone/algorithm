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


int a0, a1, b0, b1;
int __lcm(int a, int b){
    return a * b / __gcd(a, b);
}


void solve() {
    cin >> a0 >> a1 >> b0 >> b1;
    int count = 0;
    int i = 1;
    // 分析出：x必须是b1的约数
    while(i * i <= b1){ // 在b1的约数中逐个枚举检查
        if(b1 % i == 0){
            // 对于每个约数x，检查两个条件：
            int x = i; // 约数总是成对出现的
            // 条件1+条件2
            if(__gcd(x, a0) == a1 && __lcm(x, b0) == b1){
                count += 1;
            }

            if(i * i != b1){ // 跳过==的情况，防止重复计数
                x = b1 / i; // 成对的约数
                if(__gcd(x, a0) == a1 && __lcm(x, b0) == b1){
                    count += 1;
                }
            }
        }
        i++;
    }
    cout << count << endl;
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