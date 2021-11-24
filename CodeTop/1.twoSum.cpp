/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * [easy]
 * https://leetcode-cn.com/problems/two-sum/
 */

// @lc code=start
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashTable;
        for(int i=0;i<nums.size();i++){
            int num1=nums[i];
            int num2=target-num1;
            if(hashTable.find(num2)!=hashTable.end()){
                return {i,hashTable[num2]};
            }
            hashTable[num1]=i;
        }
        return {};
    }
};
// @lc code=end

