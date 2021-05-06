/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



#include <vector>
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