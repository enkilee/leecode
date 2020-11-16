/*
 * @Author: your name
 * @Date: 2020-05-05 17:32:54
 * @LastEditTime: 2020-05-06 23:16:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\TiaoYueYouXi2_no45.cpp
 * 

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;


int jump(vector<int>& nums) 
{
    int end=0;//初始化边界
    int maxPosition;
    int steps=0;
    for(int i=0;i<nums.size();i++)
    {
        maxPosition=max(maxPosition,nums[i]+i);
        if(i==end)//遇到边界，就更新边界，并且步数加一
        {
            end=maxPosition;
            steps++;
        }
    }
    return steps;
}

int main()
{
    vector<int> test= {2,3,1,1,4};
    int res=jump(test);
    return 0;
}