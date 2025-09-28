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


// 区间筛法 - 适用于大范围 [l, r]
// 时间复杂度: O((r-l+1) log log r + sqrt(r) log log sqrt(r))
// 返回 [l, r] 区间内素数的个数
int segmentedSieve(long long l, long long r) {
    if (r < 2 || l > r) return 0;
    l = max(l, 2LL);
    
    // 对于小范围，直接使用埃氏筛更高效
    // if (r <= 10000000) {
    //     return eratosthenesSieve(static_cast<int>(l), static_cast<int>(r));
    // }
    
    int sqrtR = static_cast<int>(sqrt(r)) + 1;
    
    // 生成 sqrt(r) 以内的所有素数
    vector<bool> baseSieve(sqrtR + 1, true);
    baseSieve[0] = baseSieve[1] = false;
    vector<int> basePrimes;
    
    for (int i = 2; i <= sqrtR; i++) {
        if (baseSieve[i]) {
            basePrimes.push_back(i);
            for (int j = i * i; j <= sqrtR; j += i) {
                baseSieve[j] = false;
            }
        }
    }
    
    // 对区间 [l, r] 进行筛法
    vector<bool> segSieve(r - l + 1, true);
    
    for (int prime : basePrimes) {
        // 找到第一个 >= l 且能被 prime 整除的数
        int start = max(prime * prime, (l + prime - 1) / prime * prime);
        for (int j = start; j <= r; j += prime) {
            segSieve[j - l] = false;
        }
    }
    
    // 统计素数个数
    int count = 0;
    for (size_t i = 0; i < segSieve.size(); i++) {
        if (segSieve[i]) count++;
    }
    return count;
}

int l, r;

void solve() {
    cin >> l >> r;
    cout << segmentedSieve(l, r);
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