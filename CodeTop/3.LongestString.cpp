/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 * [medium]
 */

// @lc code=start#include <vector>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unSame;
        int maxLen = 0;
        int left = 0;
        for(int i= 0; i < s.size(); i++){
            while (unSame.find(s[i]) != unSame.end())
            {
                unSame.erase(s[left]);
                left++;
            }
            int maxLen = max(maxLen, i - left + 1);
            unSame.insert(s[i]);
        }
        return maxLen;
    }
};


// @lc code=end

#include<iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#pragma region
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unSame;
        int left = 0;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            while (unSame.find(s[i]) != unSame.end())
            {
                unSame.erase(s[left]);
                left++;
            }
            unSame.insert(s[i]);
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};


//解法二
//使用的ascii 码
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> unSame;

        int start = 0;
        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            start = max(start, unSame[s[i]]);
            maxLen = max(maxLen, i - start + 1);
            unSame[s[i]] = i + 1;
        }

        return maxLen;
    }
};

//直接使用数组记录 此改动使速度提升20%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int unSame[128] = {0};
        int n = s.size();
        int start = 0;
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            start = max(start, unSame[s[i] + 0]);
            maxLen = max(maxLen, i - start + 1);
            unSame[s[i] + 0] = i + 1;
        }
        return maxLen;
    }
};
#pragma endregion