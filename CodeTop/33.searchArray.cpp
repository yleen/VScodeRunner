/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * [Medium]
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
    }
};
// @lc code=end
#include<vector>
using namespace std;
//二分搜索 由于数组分段有序 需要判断处于哪一段
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[0] <= nums[mid]){
                if(nums[mid] > target && target >= nums[0]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(nums[mid] < target && target <= nums[n - 1]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};