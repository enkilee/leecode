/*
* @Author: your name
* @Date: 2020-04-20 20:11:09
 * @LastEditTime: 2020-04-21 09:16:23
 * @LastEditors: Please set LastEditors
* @Description: 生命游戏
* @FilePath: \leecodee:\Data Structures & algorithms Using C++\houjieCPP\no289.cpp
* 
* 这题很经典！要看明白！
* 
* 生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：
1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

* 
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

void gameOfLife(vector<vector<int>> &board)
{
    int neighbors[3] = {0, 1, -1};

    int rows = board.size();
    int cols = board[0].size();

    //create copy [][]
    vector<vector<int>> copyBoard(rows, vector<int>(cols, 0));

    //copy from original
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            copyBoard[row][col] = board[row][col];
        }
    }

    //遍历每一个格子里的细胞
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            // 对于每一个细胞统计其八个相邻位置里的活细胞数量
            int liveneighbors = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (!neighbors[i] == 0 && neighbors[j] == 0)
                    {
                        int r = (row + neighbors[i]);
                        int c = (col + neighbors[j]);
                        // 查看相邻的细胞是否是活细胞
                        if ((r < rows && r >= 0) && (c < cols && c >= 0) && (copyBoard[r][c] == 1))
                        {
                            liveneighbors += 1;
                        }
                    }
                }
            }
            if ((copyBoard[row][col] == 1) && (liveneighbors < 2 || liveneighbors > 3))
            {
                board[row][col] = 0;
            }
            // 规则 4
            if (copyBoard[row][col] == 0 && liveneighbors == 3)
            {
                board[row][col] = 1;
            }
        }
    }
}

// method 2:
/*
方法一中 O(mn)O(mn) 的空间复杂度在数组很大的时候内存消耗是非常昂贵的。
题目中每个细胞只有两种状态 live(1) 或 dead(0)，但我们可以拓展一些复合状态使其包含之前的状态。
举个例子，如果细胞之前的状态是 0，但是在更新之后变成了 1，我们就可以给它定义一个复合状态 2。
这样我们看到 2，既能知道目前这个细胞是活的，还能知道它之前是死的。

算法:

遍历 board 中的细胞。

根据数组的细胞状态计算新一轮的细胞状态，这里会用到能同时代表过去状态和现在状态的复合状态。

具体的计算规则如下所示：

规则 1：如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡。这时候，将细胞值改为 -1，代表这个细胞过去是活的现在死了；

规则 2：如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活。这时候不改变细胞的值，仍为 1；

规则 3：如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡。这时候，将细胞的值改为 -1，代表这个细胞过去是活的现在死了。可以看到，因为规则 1 和规则 3 下细胞的起始终止状态是一致的，因此它们的复合状态也一致；

规则 4：如果死细胞周围正好有三个活细胞，则该位置死细胞复活。这时候，将细胞的值改为 2，代表这个细胞过去是死的现在活了。

根据新的规则更新数组；

现在复合状态隐含了过去细胞的状态，所以我们可以在不复制数组的情况下完成原地更新；

对于最终的输出，需要将 board 转成 0，1 的形式。因此这时候需要再遍历一次数组，将复合状态为 2 的细胞的值改为 1，复合状态为 -1 的细胞的值改为 0。

*/
void gameOfLife2(vector<vector<int>> &board)
{
    int neighbors[3] = {0, 1, -1};
    int rows = board.size();
    int cols = board[0].size();
    // 遍历面板每一个格子里的细胞
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {

            // 对于每一个细胞统计其八个相邻位置里的活细胞数量
            int liveNeighbors = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {

                    if (!(neighbors[i] == 0 && neighbors[j] == 0))
                    {
                        // 相邻位置的坐标
                        int r = (row + neighbors[i]);
                        int c = (col + neighbors[j]);

                        // 查看相邻的细胞是否是活细胞
                        if ((r < rows && r >= 0) && (c < cols && c >= 0) && (abs(board[r][c]) == 1))
                        {
                            liveNeighbors += 1;
                        }
                    }
                }
            }

            // 规则 1 或规则 3
            if ((board[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3))
            {
                // -1 代表这个细胞过去是活的现在死了
                board[row][col] = -1;
            }
            // 规则 4
            if (board[row][col] == 0 && liveNeighbors == 3)
            {
                // 2 代表这个细胞过去是死的现在活了
                board[row][col] = 2;
            }
        }
    }

    // 遍历 board 得到一次更新后的状态
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (board[row][col] > 0)
            {
                board[row][col] = 1;
            }
            else
            {
                board[row][col] = 0;
            }
        }
    }
}

int main()
{

    return 0;
}