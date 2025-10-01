#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 666623333;
const int MAXP = 1000000; // sqrt(1e12) = 1e6

vector<int> primes;
bool is_composite[MAXP + 10];

// 欧拉筛预处理质数
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_composite[i * p] = true;
            if (i % p == 0) break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int l, r;
    cin >> l >> r;
    
    // 预处理质数
    sieve(MAXP);
    
    int len = r - l + 1;
    vector<int> val(len), phi(len);
    
    // 初始化
    for (int i = 0; i < len; i++) {
        val[i] = l + i;
        phi[i] = l + i;
    }
    
    // 用每个质数筛区间
    for (int p : primes) {
        if (p * p > r) break; // 优化：p > sqrt(r) 时，p^2 > r
        
        // 找到 [l, r] 中第一个 >= l 且能被 p 整除的数
        int start = (l + p - 1) / p * p; // ceil(l/p) * p
        if (start < p * p) start = p * p; // 确保处理的是合数（其实不需要，但无害）
        
        for (int j = start; j <= r; j += p) {
            int idx = j - l;
            // 除尽所有的 p
            if (val[idx] % p == 0) {
                phi[idx] = phi[idx] / p * (p - 1);
                while (val[idx] % p == 0) {
                    val[idx] /= p;
                }
            }
        }
    }
    
    // 处理剩余的大质因子
    for (int i = 0; i < len; i++) {
        if (val[i] > 1) {
            phi[i] = phi[i] / val[i] * (val[i] - 1);
        }
    }
    
    // 计算答案
    int sum_i = (l + r) % MOD * ((r - l + 1) % MOD) % MOD;
    if (sum_i % 2 == 0) sum_i = sum_i / 2 % MOD;
    else sum_i = (sum_i % MOD) * ((MOD + 1) / 2) % MOD; // 处理除法
    
    // 更简单的等差数列求和
    auto sum_range = [&](int a, int b) -> int {
        if (a > b) return 0;
        int cnt = (b - a + 1) % MOD;
        int sum = (a % MOD + b % MOD) % MOD;
        return cnt * sum % MOD * ((MOD + 1) / 2) % MOD; // 乘以 2 的逆元
    };
    
    int sum_phi = 0;
    for (int i = 0; i < len; i++) {
        sum_phi = (sum_phi + phi[i]) % MOD;
    }
    
    int ans = (sum_range(l, r) - sum_phi + MOD) % MOD;
    cout << ans << endl;
    
    return 0;
}