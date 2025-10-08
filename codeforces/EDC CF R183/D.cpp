#pragma GCC optimize("O3", "inline", "omit-frame-pointer", "unroll-loops",     \
                     "fast-math")
#include <bits/stdc++.h>
using namespace std;

// Types
#define ll long long
#define int ll
#define float double
// Aliases
#define x first
#define y second
#define endl '\n'
// Comparison
#define is0(x) (fabs(x) < eps)
#define feq(x, y) (is0(x - y))
#define fge(x, y) (x > y || feq(x, y))
#define fle(x, y) (x < y || feq(x, y))
#define peq(a, b) (is0(a.x - b.x) && is0(a.y - b.y))
// Math
#define mod(x) ((x + MOD) % MOD)
#define updiv(u, d) ((u + d - 1) / d)
// Debug
#define dbg(a) cout << "Dbg: " << #a << " = " << a << endl;

// const db eps = 1e-8;
// const int MOD = 1e9 + 7;
const int N = 100;

int n, k;
int memo[N][N*N];
int a[N];
void cal(int x, int y){
    while(x < y){
        swap(a[x], a[y]);
        x++;
        y--;
    }
}

int dfs(int re, int up){
    if(memo[re][up]){
        if(memo[re][up] == -1){
            return false;
        }
        return true;
    }
    if(re < 0 || up < 0){
        return false;
    }
    if(re == 0){
        if(up == 0){
            return true;
        }
        return false;
    }
    for(int i = re; i >= 1; i--){
        int offer = i * (i + 1) / 2;
        if(offer > up){
            continue;
        }
        if(dfs(re - i, up - offer)){
            memo[re][up] = i;
            return true;
        }
    }
    memo[re][up] = -1;
    return false;
}
void solve() {
    cin >> n >> k;
    int all = n * (n + 1) / 2;
    int up = all - k;
    int re = n;
    vector<int> v;
    if(dfs(n, up) == 0){
        cout << 0 << endl;
        return;
    }
    while(re > 0){
        int len = memo[re][up];
        v.push_back(len);
        re -= len;
        up -= len * (len + 1) / 2;
    }
    for(int i = 1; i <= n; i++){
        a[i] = n + 1 - i;
    }
    int l = 1;
    for(auto len : v){
        int r = l + len - 1;
        cal(l, r);
        l = r + 1;
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
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