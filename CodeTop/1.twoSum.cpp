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
        unordered_map<int, int> hashTable;
        for(int i = 0; i < nums.size(); i++){
            int deterNum = target - nums[i];
            if(hashTable.find(deterNum) != hashTable.end()){
                return {i, hashTable[deterNum]};
            }
            hashTable[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end