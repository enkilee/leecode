/*
 * @Author: your name
 * @Date: 2020-04-09 10:45:30
 * @LastEditTime: 2020-04-09 10:49:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no22.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector<string> res={};

vector<string> generateParenthesis(int n)
{
    dfs(n,n,"");
    return res;
}
void dfs(int left,int right,string curStr)
{
    if(left==0 && right==0)
    {
        res.push_back(curStr);
        return;
    }
    if(left>0)
    {
        dfs(left-1,right,curStr+"(");
    }
    if(right>left)
    {
        dfs(left,right-1,curStr+")");
    }
}

int main()
{
    vector<string> result=generateParenthesis(3);
    for(auto str:result)
    {
        cout<<str<<endl;
    }
    return 0;
}