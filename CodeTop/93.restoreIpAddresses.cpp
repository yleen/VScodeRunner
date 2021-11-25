/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    static constexpr int SEG_COUNT = 4;
    vector<string> ans;
    vector<int> segments;
public:
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }
    void dfs(string s, int segIndex, int s_index){

        if(segIndex == SEG_COUNT){
            if(s_index == s.size()){
                string add_Str;
                for(int i = 0; i < SEG_COUNT; i++){
                    add_Str += i != SEG_COUNT - 1 ? to_string(segments[i]) + "." : to_string(segments[i]);
                }
                ans.push_back(add_Str);
            }
            return;
        }


        if(s_index == s.size()){
            return;
        }

        if(s[s_index] == '0'){
            segments[segIndex] = 0;
            dfs(s, segIndex + 1, s_index + 1);
        }

        int addr_seg = 0;
        for(int i = s_index; i < s.size(); i++){
            addr_seg = addr_seg * 10 + (s[i] - '0');
            if(addr_seg > 0 && addr_seg <= 255){
                segments[segIndex] = addr_seg;
                dfs(s, segIndex + 1, i + 1);
            }else{
                break;
            }
        }
    }
};
// @lc code=end