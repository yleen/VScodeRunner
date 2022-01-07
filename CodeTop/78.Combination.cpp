/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集 全组合
 * [medium]
 * https://leetcode-cn.com/problems/subsets/
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        for(int  i = 0; i < nums.size(); i++){
            int size = res.size();
            for(int j = 0; j < size; j++){
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
// @lc code=end

//直接从前遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        for(int i = 0; i < nums.size(); i++){
            int size = res.size();
            for(int j = 0; j < size; j++){
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};