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

int n, m;

vector<int> fa;
vector<int> sz;
int sum_sz;
void init(int n){
    sum_sz = n;
    fa.resize(n + 1);
    sz.resize(n + 1);
    for(int i = 0; i <= n; i++){
        fa[i] = i;
        sz[i] = 1;
    }
}
int find(int x){
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
bool merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy){
        return false;
    }
    sum_sz--;
    fa[fx] = fy;
    sz[fy] += fx;
    return true;
}
int size(int x){
    return sz[x];
}

void solve() {
    while(cin >> n >> m){
        init(n);
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }    
        cout << sum_sz - 1 << endl;
    }
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