/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
//法一 深度/广度  优先
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int columns = grid[0].size();
        int count = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                if (grid[r][c] == '1')
                {
                    //dfs(grid,r,c);
                    bfs(grid, r, c);
                    count++;
                }
            }
        }
        return count;
    }
    //深度优先
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        grid[x][y] = '0';
        int rows = grid.size();
        int columns = grid[0].size();
        if (x - 1 >= 0 && grid[x - 1][y] == '1')
            dfs(grid, x - 1, y);
        if (y - 1 >= 0 && grid[x][y - 1] == '1')
            dfs(grid, x, y - 1);
        if (x + 1 < rows && grid[x + 1][y] == '1')
            dfs(grid, x + 1, y);
        if (y + 1 < columns && grid[x][y + 1] == '1')
            dfs(grid, x, y + 1);
    }
    //广度优先
    void bfs(vector<vector<char>> &grid, int x, int y)
    {
        queue<pair<int, int>> neighbors;
        int rows = grid.size();
        int columns = grid[0].size();
        neighbors.push({x, y});
        while (!neighbors.empty())
        {
            auto xy = neighbors.front();
            neighbors.pop();
            int x = xy.first, y = xy.second;
            if (x - 1 >= 0 && grid[x - 1][y] == '1')
            {
                grid[x - 1][y] = '0';
                neighbors.push({x - 1, y});
            }
            if (y - 1 >= 0 && grid[x][y - 1] == '1')
            {
                grid[x][y - 1] = '0';
                neighbors.push({x, y - 1});
            }
            if (x + 1 < rows && grid[x + 1][y] == '1')
            {
                grid[x + 1][y] = '0';
                neighbors.push({x + 1, y});
            }
            if (y + 1 < columns && grid[x][y + 1] == '1')
            {
                grid[x][y + 1] = '0';
                neighbors.push({x, y + 1});
            }
        }
    }
};

// 法二 并查集
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int columns = grid[0].size();
        UnionFind uf(grid);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                if (grid[r][c] == '1')
                {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r - 1][c] == '1')
                        uf.uninte((r - 1) * columns + c, r * columns + c);
                    if (c - 1 >= 0 && grid[r][c - 1] == '1')
                        uf.uninte(r * columns + c - 1, r * columns + c);
                    if (r + 1 < rows && grid[r + 1][c] == '1')
                        uf.uninte((r + 1) * columns + c, r * columns + c);
                    if (c + 1 < columns && grid[r][c + 1] == '1')
                        uf.uninte(r * columns + c + 1, r * columns + c);
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
    UnionFind(vector<vector<char>> &grid)
    {
        count = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                if (grid[r][c] == '1')
                {
                    parent.push_back(r * columns + c);
                    count++;
                }
                else
                {
                    parent.push_back(-1);
                }
                size.push_back(1);
            }
        }
    }

    void uninte(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (size[rootX] > size[rootY])
        {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        else
        {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        count--;
    }

    int find(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return parent[x];
    }

    bool connected(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        return rootX == rootY;
    }
    int getCount()
    {
        return count;
    }
};
// @lc code=end
