/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 * [medium]
 */

// @lc code=start#include <vector>
#include<iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> noSam; //hashmap
        int length=0;
        int left=0;
        for (int i = 0; i < s.size(); i++)
        {
            while(noSam.find(s[i])!=noSam.end()){//while!!!! 多次填成if
                noSam.erase(s[left]);
                left++;
            }
            length=max(length,i-left+1);
            noSam.insert(s[i]);
            
            
        }

        return length;
        
    }   
};


//解法二
//使用的ascii 码
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last;//hashmap

        int n=s.size();

        int res=0;
        int start=0;
        for(int i=0;i<n;i++){
            start=max(start,last[s[i]]);
            res=max(res,i-start+1);
            last[s[i]]=i+1;
        }

        return res;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128]={0};//直接使用数组记录 此改动使速度提升20%

        int n=s.size();

        int res=0;
        int start=0;
        for(int i=0;i<n;i++){
            int index=s[i]+0;
            start=max(start,last[index]);
            res=max(res,i-start+1);
            last[index]=i+1;
        }

        return res;
    }
};
// @lc code=end

