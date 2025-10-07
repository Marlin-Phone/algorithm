/**
 * @nc app=nowcoder id=73e0552b78474a9086781e47f4e01d73 topic=385 question=314258 lang=C++
 * 2025-10-07 21:13:51
 * https://www.nowcoder.com/practice/73e0552b78474a9086781e47f4e01d73?tpId=385&tqId=314258
 * [BGN4] 买橘子
 */

/** @nc code=start */

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    std::cin >> n;
    if(n % 2 == 1){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i <= n / 6 + 1; i++){
        int temp = n - 6 * i;
        if((n - 6 * i) % 8 == 0){
            cout << temp / 8 + i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

/** @nc code=end */
