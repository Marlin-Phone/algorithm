#include <iostream>
#include <vector>
using namespace std;

const int MOD = 9901;

// 快速幂 (base^exp) % MOD
long long qpow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

// 等比数列求和: 1 + p + p^2 + ... + p^n (mod MOD)
long long geoSum(long long p, long long n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    
    p %= MOD;
    if (p == 0) return 1; // 1 + 0 + 0 + ... = 1
    if (p == 1) return (n + 1) % MOD;
    
    // S = (p^(n+1) - 1) / (p - 1)
    long long numerator = (qpow(p, n + 1) - 1 + MOD) % MOD;
    long long denominator = (p - 1 + MOD) % MOD;
    
    // 求 denominator 的逆元 (费马小定理)
    long long inv = qpow(denominator, MOD - 2);
    return (numerator * inv) % MOD;
}

int main() {
    long long a, b;
    cin >> a >> b;
    
    if (b == 0) {
        cout << 1 << endl;
        return 0;
    }
    
    long long result = 1;
    long long temp = a;
    
    // 质因数分解 a
    for (long long i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            int cnt = 0;
            while (temp % i == 0) {
                cnt++;
                temp /= i;
            }
            // i 是质因子，cnt 是指数
            long long n = (long long)cnt * b; // a^b 中 i 的指数
            result = (result * geoSum(i, n)) % MOD;
        }
    }
    
    // 如果 temp > 1，说明还有一个大质因子
    if (temp > 1) {
        long long n = b; // 指数为 1 * b
        result = (result * geoSum(temp, n)) % MOD;
    }
    
    cout << result << endl;
    return 0;
}