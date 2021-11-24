/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 * [medium]
 * https://leetcode-cn.com/problems/spiral-matrix/
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
private:
    static constexpr int directions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool> > visited(rows, vector<bool>(columns));
        int row=0,column=0,directIndex=0;
        int size=matrix.size()*matrix[0].size();
        vector<int> res(size);
        for(int i=0;i<size;i++){
            res[i]=matrix[row][column];
            visited[row][column]=true;
            int nextRow=row+directions[directIndex][0],nextColumn=column+directions[directIndex][1];
            if(nextRow<0||nextColumn<0||nextRow>rows-1||nextColumn>columns-1||visited[nextRow][nextColumn]){
                directIndex=(directIndex+1)%4;
            }
            row+=directions[directIndex][0];
            column+=directions[directIndex][1];
        }
        return res;
    }
};
// @lc code=end

