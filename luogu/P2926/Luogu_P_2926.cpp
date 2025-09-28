#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000 + 10;

int cnt[MAX];
int total[MAX]; // total[x] = 有多少个 A_j 满足 A_j | x

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    // 倍数累加 倍数贡献法（用于因数/整除统计）
    for (int d = 1; d < MAX; d++) {
        if (cnt[d] == 0) continue;
        for (int k = d; k < MAX; k += d) {
            total[k] += cnt[d];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << total[A[i]] - 1 << '\n';
    }

    return 0;
}