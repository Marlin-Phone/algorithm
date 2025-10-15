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
    ll n, p, m;
    cin >> p >> m;
    if(p == 2){
        cout << (m / 2) + 1 << '\n';
        return;
    }
    if (m == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << m / p + 1 << '\n';
    }
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