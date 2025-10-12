/**
 * @nc app=nowcoder id=032c72fab5fe4a2ea8e11d40378a493d topic=385 question=11254466 lang=C++
 * 2025-10-12 19:26:25
 * https://www.nowcoder.com/practice/032c72fab5fe4a2ea8e11d40378a493d?tpId=385&tqId=11254466
 * [BGN10] 九倍平方数
 */

/** @nc code=start */

#include <bits/stdc++.h>
using namespace std;

int sumNum(int num){
    int res = 0;
    while(num){
        res += num % 10;
        num /= 10;
    }
    return res;
}

void solve() {
    string str_n;
    cin >> str_n;
    
    int size = str_n.size();
    int sum = 0;
    vector<int> cnt(10, 0);

    for(int i = 0; i < size; i++){
        int num = str_n[i] - '0';
        cnt[num]++;
        sum += num;
    }
    // for(int i = 0; i <= 9; i++){
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;

    if(sum % 9 == 0){
        cout << "YES" << endl;
    }else{
        int need = sum % 9; // 1-8
        // cout << need << endl;
        for(int two = 0; two <= cnt[2] && two <= 8; two++){
            for(int three = 0; three <= cnt[3]; three++){
                if((need + 2 * two + 6 * three) % 9 == 0){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
        return;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// 64 位输出请用 printf("%lld")

/** @nc code=end */
