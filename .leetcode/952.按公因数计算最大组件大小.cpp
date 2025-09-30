#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=952 lang=cpp
 *
 * [952] 按公因数计算最大组件大小
 */

// @lc code=start
class Solution {
public:

    unordered_map<int, int> first;
    vector<int> fa;
    vector<int> sz;
    void init(int n){
        sz.assign(n, 1);
        fa.resize(n + 1);
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx == fy){
            return false;
        }
        fa[fx] = fy;
        sz[fy] += sz[fx];
        return true;
    }
    int size(int x){
        return sz[x];
    }

    void factors(int n, int idx){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                if(first.count(i) == 0){
                    first[i] = idx;
                }else{
                    merge(first[i], idx);
                }
                while(n % i == 0){
                    n /= i;
                }
            }
        }
        if(n > 1){
            if(first.count(n) == 0){
                first[n] = idx;
            }else{
                merge(first[n], idx);
            }
        }
        return;
    }
    int largestComponentSize(vector<int>& nums) {
        init(nums.size());
        for(int i = 0; i < nums.size(); i++){
            factors(nums[i], i);
        }
        return *max_element(sz.begin(), sz.end());
    }
};
// @lc code=end

