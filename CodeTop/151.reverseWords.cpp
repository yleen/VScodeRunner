/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 * [medium]
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/
 */

// @lc code=start
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int left=0,right=s.size()-1;
        while(left<right&&s[left]==' ')left++;
        while(left<right&&s[right]==' ')right--;
        string word,newStr;
        stack<string> skStr;
        while (left<=right)
        {
            if (s[left]!=' ')
            {
                word+=s[left];
                if (left==right||s[left+1]==' ')
                {
                    skStr.push(word);
                    word="";
                }
            }
            left++;
        }
        while (!skStr.empty())
        {
            newStr+=skStr.top();skStr.pop();
            if (!skStr.empty())
            {
                newStr+=' ';
            }
            
        }
        return newStr;
    }
};
// @lc code=end

