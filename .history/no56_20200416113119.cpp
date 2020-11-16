/*
 * @Author: your name
 * @Date: 2020-04-16 10:55:36
 * @LastEditTime: 2020-04-16 11:31:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no56.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()==0)
    {
        return {};
    }
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> merged;
    for(int i=0;i<intervals.size();++i)
    {
        int L = intervals[i][0];
        int R = intervals[i][1];
        if(!merged.size()||merged.back()[1]<L)
        {
            merged.push_back({L,R});
        }
        else
        {
            merged.back()[1]=max(merged.back()[1],R);
        }
    }
    return merged;
}
// method 2:
vector<vector<int>> merge2(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;
    for(int i=0;i<intervals.size();)
    {
        int t=intervals[i][1];
        int j=i+1;
        while(j<intervals.size() && intervals[j][0]<t)
        {
            t=max(t,intervals[i][1]);
            j++;
        }
        res.push_back({intervals[i][0],t});
        i++;
    }
}
int main()
{
    vector<vector<int>> res={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result;
    result=merge(res);
    return 0;
}