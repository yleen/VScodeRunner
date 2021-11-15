/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
//暴力解法
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l_max(n);
        vector<int> r_max(n);
        int capcity = 0;
        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];
        for(int l = 1; l < n; l++){
            l_max[l] = max(height[l], l_max[l - 1]);
        }
        for(int r = n - 2; r >= 0; r--){
            r_max[r] = max(height[r], r_max[r + 1]);
        }
        for(int i = 0; i < height.size(); i++){
            capcity += min(l_max[i], r_max[i]) - height[i];
        }
        return capcity;
    }
};
// @lc code=end

