/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<vector>
#include<queue>
#include<deque>
using namespace std;
//优先队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> qClub;
        for(int i = 0; i < k; i++){
            qClub.emplace(nums[i], i);
        }
        vector<int> res = {qClub.top().first};//先把第一组最大值加进去
        for(int i = k; i < n; i++){
            qClub.emplace(nums[i], i);
            while(qClub.top().second <= i - k){//为啥使用while不是用if呢，qClub中存储的是所有的数，if的话只删除一个 下一个top有可能还不是当前的club
                qClub.pop();
            }
            res.push_back(qClub.top().first);
        }
        return res;
    }
};
//单调队列：队列有序
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dqClub;
        for(int i = 0; i < k; i++){
            while (!dqClub.empty() && nums[i] >= nums[dqClub.back()])
            {
                dqClub.pop_back();
            }
            dqClub.push_back(i);
        }
        vector<int> res = {nums[dqClub.front()]};
        for(int i = k; i < n; i++){
            while(!dqClub.empty() && nums[i] >= nums[dqClub.back()]){
                dqClub.pop_back();
            }
            dqClub.push_back(i);
            while (dqClub.front() <= i -k) //i - k是每一个club的初始位置
            {
                dqClub.pop_front();//注意用的是pop_front 
            }
            res.push_back(nums[dqClub.front()]);//此处用的是front 该元素还会存在的
        }
        return res;
    }
};
// @lc code=end