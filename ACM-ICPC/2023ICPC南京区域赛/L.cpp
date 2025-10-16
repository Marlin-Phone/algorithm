#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define dbg(a) cout << #a << " = " << (a) << endl

int n, m;

struct node{
    int c; // 件数
    int to; // 价值
};

// 计算最小总运费
int dfs(vector<node>& A){
    // A按照单价降序排序
    sort(A.begin(), A.end(), [&](const node& q1, const node& q2){
        return q1.to > q2.to;
    });
    int len = A.size();
    int ans = 0;
    for(int i = 0; i <= len - 1; i++){
        if(A[i].c <= 0 && i < len - 1){
            A[i + 1].c += A[i].c; // 负数合并到下一批
            continue;
        }
        if(i == len - 1){
            ans += (A[i].c + m - 1) / m * A[i].to;
            continue;
        }
        ans += (A[i].c + m - 1) / m * A[i].to;
        if(A[i].c % m){
            A[i + 1].c -= m - (A[i].c % m); // 借“缺额”填满当前车
        }
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    m = k / 2; // 每辆车最多可以装m个“重量为2”的等效货物
    vector<node> F, A;
    for(int i = 1; i <= n; i++){
        int ci, wi, fi;
        cin >> ci >> wi >> fi;
        if(wi == 2){
            A.push_back({ci, fi}); // A存放重量为2的货物
        }else{
            F.push_back({ci, fi}); // F存放重量为1的货物
        }
    }
    // 对重量为1的货物进行单价的降序排序，高价值的优先处理（贪心）
    sort(F.begin(), F.end(), [&](const node& q1, const node& q2){
        return q1.to > q2.to;
    });
    int len = F.size();
    // 将重量为1的货物打包为重量为2的货物
    for(int i = 0; i <= len - 1; i++){
        if(i == len - 1){
            A.push_back({(F[i].c + 1) / 2, F[i].to});
            continue;
        }
        A.push_back({(F[i].c + 1) / 2, F[i].to});
        if(F[i].c % 2){
            F[i + 1].c -= 1;
        }
    }
    // 贪心思想：高单价货物优先装满车。若当前货物没装满一车，就“假设”从下一批（单价<=当前）借货来填满，从而按照整个计费
    cout << dfs(A) << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}