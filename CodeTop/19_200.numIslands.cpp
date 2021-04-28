/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int columns=grid[0].size();
        UnionFind uf(grid);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                if(grid[r][c]=='1'){
                    grid[r][c]='0';
                    if(r-1>=0&&grid[r-1][c]=='1') uf.uninte((r-1)*columns+c,r*columns+c);
                    if(c-1>=0&&grid[r][c-1]=='1') uf.uninte(r*columns+c-1,r*columns+c);
                    if(r+1<rows&&grid[r+1][c]=='1') uf.uninte((r+1)*columns+c,r*columns+c);
                    if(c+1<columns&&grid[r][c+1]=='1') uf.uninte(r*columns+c+1,r*columns+c);
                }
            }
            
        }
        return uf.getCount();
        
    }
};

class UnionFind
{
private:
    vector<int> parent;
    vector<int> size;
    int count;
public:
    UnionFind(vector<vector<char>>& grid){
        count=0;
        int rows=grid.size();
        int columns=grid[0].size();
        for(int r=0;r<rows;r++){
            for (int c = 0; c < columns; c++)
            {
                if(grid[r][c]=='1'){
                    parent.push_back(r*columns+c);
                    count++;
                }else{
                    parent.push_back(-1);
                }   
                size.push_back(1);
            }
            
        }
    }

    void uninte(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX==rootY)
            return;
        if(size[rootX]>size[rootY]){
            parent[rootY]=rootX;
            size[rootX]+=size[rootY];
        }else{
            parent[rootX]=rootY;
            size[rootY]+=size[rootX];
        }
        count--;
    }

    int find(int x){
        while (x!=parent[x])
        {
            parent[x]=parent[parent[x]];
            x=parent[x];
        }
        return parent[x];
    }

    bool connected(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        return rootX==rootY;
    }
    int getCount(){
        return count;
    }
};
// @lc code=end

