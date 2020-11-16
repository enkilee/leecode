/*
 * @Author: your name
 * @Date: 2020-04-20 19:40:43
 * @LastEditTime: 2020-04-20 19:45:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no1111.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

vector<int> maxDepthAfterSplit(string seq)
{
    vector<int> ans;
    int d=0;
    for(char& c:seq)
    {
        if(c=='(')
        {
            ++d;
            ans.push_back(d%2);
        }
        else
        {
            ans.push_back(d%2);
            --d;
        }
    }
    return ans;
}

vector<int> maxDepthAfterSplit2(string seq)
{
    vector<int> ans;
        for (int i = 0; i < (int)seq.size(); ++i) {
            ans.push_back(i & 1 ^ (seq[i] == '('));
        }
        return ans;
}
int main()
{
   
    return 0;
}