/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 * [easy]
 * https://leetcode-cn.com/problems/add-strings/
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;int j=num2.size()-1;
        int add=0;
        string res="";
        while(i>=0||j>=0||add!=0){
            int a=i>=0?num1[i]-'0':0;
            int b=j>=0?num2[j]-'0':0;
            int sum=a+b+add;
            res.push_back(sum%10+'0');
            add=sum/10;
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

