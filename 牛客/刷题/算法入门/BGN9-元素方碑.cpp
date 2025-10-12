/**
 * @nc app=nowcoder id=5c6e7ed4726e41f4ac99a4dedf1e5bb2 topic=385 question=11254465 lang=C++
 * 2025-10-12 20:06:48
 * https://www.nowcoder.com/practice/5c6e7ed4726e41f4ac99a4dedf1e5bb2?tpId=385&tqId=11254465
 * [BGN9] 元素方碑
 */

/** @nc code=start */

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    if(sum % n != 0){
        cout << "NO" << endl;
        return;
    }

    int avg = sum / n;
    for(int i = 2; i <= n - 1; i++){
        if(a[i - 1] < avg){
            int diff = avg - a[i - 1];
            a[i - 1] = avg;
            a[i + 1] -= diff;
        }else if(a[i - 1] > avg){
            int diff = a[i - 1] - avg;
            a[i - 1] = avg;
            a[i + 1] += diff;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    if(a[n] == avg){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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
