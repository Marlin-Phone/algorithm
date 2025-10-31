#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dbg(a) cout << #a << " = " << (a) << endl

int a, b, p;
int sum_set;
vector<int> fa;

vector<int> sz;
            
void init(int n){
    fa.resize(n + 1);
    sz.resize(n + 1, 1);
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
}
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy){
        return false;
    }
    fa[fx] = fy;
    sz[fy] += sz[fx];
    sum_set--;
    return true;
}
int size(int x){
    return sz[x];
}

void solve(){
    cin >> a >> b >> p;
    sum_set = b - a + 1;
    init(b);
    vector<bool> isPrime(b + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= b; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= b; j += i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = p; i <= b; i++){
        if(isPrime[i]){
            int last_j = 0;
            for(int j = i; j <= b; j += i){
                if(j < a){
                    continue;
                }
                // dbg(i);
                // dbg(j);
                // cout << endl;
                if(last_j != 0){
                    merge(last_j, j);
                }
                last_j = j;
            }
        }
    }

    cout << sum_set << endl;
}

signed main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}