/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * [easy]
 * https://leetcode-cn.com/problems/binary-search/
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,pivot=0,right=nums.size()-1;
        while (left<=right)
        {
            pivot=left+(right-left)/2;
            //此处有一个问题 pivot可有两种方法求值，另一种为（left+right）/2 哪种比较好呢。 应该是上面这种，因为若right较大时不会溢出
            if(nums[pivot]==target) return pivot;
            if(nums[pivot]>target) {
                right=pivot-1;
            }
            else{
                left=pivot+1;
            }
        }
        return -1;
        
    }
};
// @lc code=end

