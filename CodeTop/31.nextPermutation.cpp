/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 * https://leetcode-cn.com/problems/next-permutation/
 * [Medium]
 * ???????
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        int j = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1])
        {
            i--;
        }
        i--;
        if(i >= 0){
            while (j > i && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums,i + 1);
    }
    void reverse(vector<int>& nums, int start){
        int i = start;
        int j = nums.size() - 1;
        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
// @lc code=end
//图反了 https://zhuanlan.zhihu.com/p/45007701
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        int j = nums.size() - 1;
        
        while (i > 0 && nums[i] <= nums[i - 1])
        {
            i--;
        }
        i--; //想一下移动的情景，要取的是i-1的位置
        if(i >= 0){
            while (j >= i && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums, i + 1);
    }
    void reverse(vector<int>& nums, int start){
        int i = start;
        int j = nums.size() - 1;
        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};