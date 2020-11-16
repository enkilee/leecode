/*
 * @Author: your name
 * @Date: 2020-03-26 16:30:47
 * @LastEditTime: 2020-03-26 16:43:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\mianshi按摩师.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
using namespace std;


int massage(vector<int>& nums)
{
    int len=nums.size();
    if(len==0)
    {
        return 0;
    }
    if(len==1)
    {
        return nums[0];
    }
    vector<int> dp(len,0);
    


    //遍历迄今为止的最大值，两种情况取较大：
    //1：预约本次，则上一次不预约（dp[i-2] + nums[i]）
    //2：本次不预约，则值为预约到上一次的最大值

 
}



int main()
{
   
    return 0;
}