#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(x) for (ll i = 1; i <= x; ++i)
#define f1(x) for (ll j = 1; j <= x; ++j)
#define lowbit(x) ((-x) & x)
#define PII pair<ll, ll>
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define eps 1e-7
#define il inline

constexpr ll mod = 1e9 + 7;

il void solve()
{
    // ll p, m;
    // cin >> p >> m;
    ll p = 1145141;
    ll m0 = 998244353;
    int last = 0;
    int now = 0;
    // for(int m = 0; m <= m0; m++){
        //------------------
        int ans = 0;
        int m = m0;
        for(int i = 0; i <= m; i++){
            if(((i ^ (p - 1)) % p) == 1){
                ans++;
            }
        }
        // ------------------
        cout << "ans = " << ans << endl;
        // now = ans;
        // if(last != now){
        //     // cout << "--------------" << endl;
        //     cout << "m = " << m % p << endl;
        //     // cout << bitset<6> (m) << endl;
        //     // cout << "ans = " << ans << endl;
        // }
        // last = now;
    // }
}
    


int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}