/*
 * @Author: your name
 * @Date: 2020-04-20 19:48:09
 * @LastEditTime: 2020-04-20 20:07:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecodee:\Data Structures & algorithms Using C++\houjieCPP\no200.cpp
 */


#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;



/*
DFS
*/
void dfs(vector<vector<char>>&grid, int r, int c)
{
    int nr=grid.size();  // 行数
    int nc=grid[0].size(); //列数

    grid[r][c]='0';
    //遍历上下左右
    if(r-1>=0 && grid[r-1][c]=='1')
        dfs(grid,r-1,c);
    if (r + 1 < nr && grid[r+1][c] == '1') 
        dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c-1] == '1') 
        dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c+1] == '1') 
        dfs(grid, r, c + 1);


}

int numIslands(vector<vector<char>>& grid) 
{
    int nr=grid.size();
    if(!nr)
    return 0;
    int nc=grid[0].size();

    int num_island=0;
    for(int r=0;r<nr;++r)
    {
        for(int c=0;c<nc;++c)
        {
            //若出现岛屿为1，数量加1
            if(grid[r][c]=='1')
            ++num_island;
            dfs(grid,r,c);
        }
    }
    return num_island;
}

/*
BFS
为了求出岛屿的数量，我们可以扫描整个二维网格。如果一个位置为 11，则将其加入队列，开始进行广度优先搜索。在广度优先搜索的过程中，每个搜索到的 11 都会被重新标记为 00。直到队列为空，搜索结束。

*/

int numIslandsWithBFS(vector<vector<char>>& grid) 
{
    int nr=grid.size();
    if(!nr)
        return 0;
    int nc=grid[0].size();
    int num_island2=0;
    for(int r=0;r<nr;++r)
    {
        for(int c=0;c<nc;++c)
        {
            if(grid[r][c]=='1')
            {
                ++num_island2;
                grid[r][c]=='0';
                queue<pair<int,int>> neighbors;
                neighbors.push({r,c});
                while(!neighbors.empty())
                {
                    auto rc=neighbors.front();
                    neighbors.pop();
                    int row=rc.first,col=rc.second;
                    if(row-1>=0 && grid[row-1][col]=='1')
                    {
                        neighbors.push({row-1,col});
                        grid[row-1][col]='0';
                    }
                    if (row + 1 < nr && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                }
            }
        }
    }
    return num_island2;
}

/*
并查集
*/
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};


int main()
{
   
    return 0;
}