/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
//hash
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {

//         unordered_set<int> num_set;
//         //注意set 与 unordered_set 区别

//         for (int i = 0; i < nums.size(); i++) {
//             num_set.insert(nums[i]);
//         }

//         for (int i = 0; i <= nums.size(); i++) {
//             if (num_set.find(nums[i]) == num_set.end()) {
//                 return i;
//             }
//         }
//         return 0;
//     }
// };

//原地hash
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {

//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             if(nums[i] != i && nums[i] < n) {
//                 swap(nums[i],nums[nums[i]]);
//                 i--;
//             }//此处操作为将数据放到正确的位置,都放回正确位置后就知道哪个是缺失的了
//         }

//         for (int i = 0; i < n; i++) {
//             if(nums[i] != i){//若不相等即一定是缺失的那个数
//                 return i;
//             }
//         }
//         return n;//如果都相等 那说明最后一个数是缺失的
//     }
// };

//异或
//找缺失数 找出现一次的数都是异或的经典应用
// 异或可以简单理解为 排除共同  0^0=0 1^0=1 0^1=1 1^1=0
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int miss = 0;//虽然0^0=0 但若缺失的是0 最终返回的也是0
        for(int i = 0; i <= n; i++){
            miss = miss ^ i;
        }

        for(auto v : nums){
            miss = miss ^ v;
        }
        return miss;
    }
};
// @lc code=end

