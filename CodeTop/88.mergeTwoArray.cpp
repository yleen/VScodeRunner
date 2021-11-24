/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 * [easy]
 * https://leetcode-cn.com/problems/merge-sorted-array/
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while (k>=0)
        {
            if(i>=0&&j>=0)
                nums1[k--]=nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
            else
                nums1[k--]=i>=0?nums1[i--]:nums2[j--];
        }
        
    }
};
// @lc code=end

