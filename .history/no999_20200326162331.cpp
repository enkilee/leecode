/*
 * @Author: your name
 * @Date: 2020-03-26 16:15:46
 * @LastEditTime: 2020-03-26 16:16:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no999.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
using namespace std;


int numRookCaptures(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='R')
                {
                    return cap(board,i,j,0,1)+cap(board,i,j,0,-1)+cap(board,i,j,1,0)+cap(board,i,j,-1,0);
                }
            }
        }
        return 0;
    }

    int cap(vector<vector<char>> &a,int x,int y,int dx,int dy)
    {
        // x,y为R的坐标
        // dx,dy为增长步长
        while(x>=0 && x<a.size() && y>=0 && y<a[x].size()&&a[x][y]!='B')
        {
            if(a[x][y]=='p')
            {
                return 1;
            }
            x+=dx;
            y+=dy;
        }
        return 0;
    }

int main()
{
   vector<vector<char>> board ={
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', 'p', '.', '.', '.', '.'},
                {'.', '.', '.', 'R', '.', '.', '.', 'p'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', 'p', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '.', '.', '.', '.'}};
    int res=numRookCaptures(board);
    return 0;
}