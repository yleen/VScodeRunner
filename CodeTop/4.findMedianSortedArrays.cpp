/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

#include<vector>
using namespace std;
//最蠢的方法 合并  时间复杂度o(m + n) 空间复杂度o(n)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int len = nums1.size() + nums2 .size();
//         vector<int> newNums(len, 0); //必须初始化vector 且需设定长度
//         int n = 0;
//         int i = 0;
//         int j = 0;
//         while (i < nums1.size() && j < nums2.size())
//         {
//             newNums[n++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
//         }
//         while(i < nums1.size()){
//             newNums[n++] = nums1[i++];
//         }
        
//         while(j < nums2.size()){
//             newNums[n++] = nums2[j++];
//         }
        
//         if(newNums.size() % 2 == 0){
//             double a = newNums[(newNums.size() - 1) / 2];
//             double b = newNums[(newNums.size() - 1) / 2 + 1];
//             return (a + b) / 2;
//         }else{
//             return newNums[(newNums.size() - 1) / 2];
//         }
//     }
// };

//略蠢的方法 双指针  时间复杂度o(m + n) 空间复杂度 o(1)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0;
//         int j = 0;
//         int k = 0;
//         int val = 0;
//         int preVal = 0;
//         int s = nums1.size() + nums2.size();
//         while (k <= s / 2)
//         {
//             preVal = val;
//             if(i < nums1.size() && (j >= nums2.size() || nums1[i] < nums2[j])){
//                 val = nums1[i++];
//             }else{
//                 val = nums2[j++];
//             }
//             k++;
//         }
        
//         if(s % 2 == 0){
//             return (val + preVal) / 2.0;
//         }else{
//             return  val;
//         }
//     }
// };


// @lc code=end