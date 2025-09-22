// https://luogu.com.cn/problem/P
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(a) cout << #a << " = " << a << endl;
#define int long long

// const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int T = 1;
int n;
int arr[N];
int help[N];

int merge(int l, int m, int r) {
    int ans = 0;

    // 统计部分
    for (int j = m + 1, i = l, sum = 0; j <= r; j++) {
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
    }

    // 正常归并排序
    int i = l;
    int a = l;
    int b = m + 1;

    while (a <= m && b <= r) {
        if (arr[a] <= arr[b]) {
            help[i++] = arr[a++];
        } else {
            help[i++] = arr[b++];
        }
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }

    for (int i = l; i <= r; i++) {
        arr[i] = help[i];
    }

    return ans;
}
int smallSum(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = l + (r - l) / 2;
    int smallSuml = smallSum(l, m);
    int smallSumr = smallSum(m + 1, r);

    return smallSuml + smallSumr + merge(l, m, r);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << smallSum(1, n);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}