#include <bits/stdc++.h>
using namespace std;

const int N = 400;          // 旅行天数最大365
const int INF = 0x3f3f3f3f; // 足够大的初始值

int n;
int days[N];                   // 出行天数
int costs[3];                  // 三种票价：1/7/30天
int dp[N];                     // dp[i]: 从第i个旅行日开始到结束的最小花费
int durations[3] = {1, 7, 30}; // 三种票的持续时间

void solved() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> costs[i];
    }

    // 边界条件：没有旅行日时费用为0
    dp[n] = 0;

    // 从后往前动态规划
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = INF; // 初始化为极大值

        // 尝试三种票
        for (int k = 0; k < 3; k++) {
            int end_day = days[i] + durations[k]; // 当前票覆盖的最后一天

            // 二分查找第一个不在覆盖范围内的旅行日
            int j = lower_bound(days + i, days + n, end_day) - days;

            // 状态转移
            dp[i] = min(dp[i], costs[k] + dp[j]);
        }
    }

    cout << dp[0] << endl;
}

int main() {
    solved();
    return 0;
}