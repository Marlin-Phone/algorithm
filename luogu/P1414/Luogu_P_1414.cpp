#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VAL = 1000000;


// 不是直接求选k个人的最大gcd，
// 而是对于每个可能的gcd值d，计算有多少个数是d的倍数，
// 然后根据这个信息来确定答案。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> cnt(MAX_VAL + 1, 0);
    int max_val = 0;
    
    // 读入数据并统计
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        max_val = max(max_val, x);
    }
    
    // num[d] 表示有多少个数是d的倍数
    vector<int> num(MAX_VAL + 1, 0);
    for (int d = 1; d <= max_val; d++) { // 调和级数 mlogm
        for (int j = d; j <= max_val; j += d) {
            num[d] += cnt[j];
        }
    }
    
    // ans[k] 表示选k个人时的最大默契程度
    vector<int> ans(n + 1, 0);
    
    // 从大到小枚举d，这样能保证ans[k]是最大的
    for (int d = max_val; d >= 1; d--) {
        if (num[d] > 0) {
            // d可以作为前num[d]个k的答案
            for (int k = 1; k <= min(num[d], n); k++) {
                ans[k] = max(ans[k], d);
            }
        }
    }
    
    // 输出结果
    for (int k = 1; k <= n; k++) {
        cout << ans[k] << '\n';
    }
    
    return 0;
}