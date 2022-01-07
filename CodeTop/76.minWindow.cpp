/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 
 * https://leetcode-cn.com/problems/minimum-window-substring/
 * [Hard]
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
    }
};
// @lc code=end

#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int length = 0;
        int minLength = INT_MAX;
        int start = 0;
        bool change = false;
        int noteAppear[128] = {0};//因为都是字符 直接用ascii码更合适 
        int noteAim[128] = {0};
        // unordered_map<char, int> noteAppear;
        // unordered_map<char, int> noteAim;
        for(int i = 0; i < t.size(); i++){
            noteAim[t[i]]++;
        }

        for(int i = 0; i < s.size(); i++){
            noteAppear[s[i]]++;
            if(noteAppear[s[i]] <= noteAim[s[i]]){
                length++;
            }
            if(length == t.size()){//length 当搜索到第一个匹配的子串时length就不会再增加了，之后每添加一个子串都会与原字串进行比较，选出最小的字串
                while(left < i && noteAppear[s[left]] > noteAim[s[left]]){//将开头没用的跳过 即开头s中不包含t的字符
                    noteAppear[s[left]]--;
                    left++;
                }
                if(i - left + 1 < minLength){
                    minLength = i - left + 1;
                    start = left;
                }
                change = true;
            }
        }
        return change? s.substr(start, minLength) : "";
    }
};