/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
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
            if(length == t.size()){
                while(left < i && noteAppear[s[left]] > noteAim[s[left]]){
                    noteAppear[s[left]]--;
                    left++;
                }
                if(i - left + 1 < minLength){
                    minLength = i - left + 1;
                    start = left;
                }
                change = true;
                minLength = min(i - left + 1, minLength);
                noteAppear[s[i]];
            }
        }
        return change? s.substr(start, minLength) : "";
    }
};
// @lc code=end

