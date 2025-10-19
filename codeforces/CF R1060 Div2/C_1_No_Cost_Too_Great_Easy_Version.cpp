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
const int N = 1e6 + 10;

int n;
int a[N], b[N];

vector<int> getPrime(int x){
    vector<int> res;
    if(x <= 1){
        return res;
    }
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            while(x % i == 0){
                x /= i;
            }
            // x /= i;
            res.push_back(i);
        }
    }
    if(x > 1){
        res.push_back(x);
    }
    return res;
}

void solve() {
    cin >> n;
    map<int, int> cnt;
    map<int, int> precnt;
    int pcnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        vector<int> res = getPrime(a[i]);
        for(auto it : res){
            cnt[it]++;
        }
        // if(isPrime(a[i])){
        //     pcnt++;
        // }
        precnt[a[i]]++;
    }

    for(auto [key, val] : cnt){
        if(val >= 2 && key != 1){
            cout << 0 << endl;
            return;
        }
    }
    
    for(auto [key, val] : precnt){
        // dbg(key);
        vector<int> res = getPrime(key + 1);
        for(auto it : res){
            // dbg(it);
            if(cnt.count(it)){
                cout << 1 << endl;
                return;
            }
        }
    }


    cout << 2 << endl;


    // if(pcnt == n){
    //     if(cnt2 == 0){
    //         cout << 2 << endl;
    //         return;
    //     }else if(cnt2 == 1){
    //         cout << 1 << endl;
    //         return;
    //     }else{
    //         cout << 0 << endl;
    //         return;
    //     }
    // }else if(pcnt == n - 1){

    // }

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