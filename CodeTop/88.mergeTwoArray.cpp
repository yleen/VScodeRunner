/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 * [easy]
 * https://leetcode-cn.com/problems/merge-sorted-array/
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    }
};
// @lc code=end

#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        m = m - 1;
        n = n - 1;
        while (k >= 0)
        {
            if(m >=0 && n >=0){
                nums1[k--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
            }else{
                nums1[k--] = m >=0 ? nums1[m--] : nums2[n--];
            }
        }
    }
};