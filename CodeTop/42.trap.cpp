/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * https://leetcode-cn.com/problems/trapping-rain-water/
 * [Hard]
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int capcity = 0;
        int l_max = height[left];
        int r_max = height[right];
        while (left < right)
        {
            l_max = max(height[left], l_max);
            r_max = max(height[right], r_max);

            if(l_max < r_max){
                capcity += l_max - height[left];
                left++;
            }else{
                capcity += r_max - height[right];
                right--;
            }
        }
        return capcity;
    }
};
// @lc code=end

//暴力解法(动态规划)
//https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/
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
//双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int capcity = 0;
        int left = 0;
        int right = n - 1;
        int l_max = height[left];
        int r_max = height[right];
        while(left < right){
            l_max = max(height[left], l_max);
            r_max = max(height[right], r_max);
            if(l_max < r_max){
                capcity += l_max - height[left];
                left++;
            }else{
                capcity += r_max - height[right];
                right--;
            }
        }
        return capcity;
    }
};