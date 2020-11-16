/*
 * @Author: your name
 * @Date: 2020-05-03 11:12:05
 * @LastEditTime: 2020-05-03 11:18:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no53.cpp
 * 
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 输入: [-2,1,-3,4,-1,2,1,-5,4],
 输出: 6
 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。 
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int len=nums.size();
    int MAX=nums[0];
    int sub=0;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<=len;j++)
        {
            sub=nums[i]+nums[j];
            if(sub>MAX)
            {
                MAX=sub;
            }
        }
    }
    return MAX;
}

int main()
{
   
    return 0;
}