/*
 * @Author: your name
 * @Date: 2020-05-03 11:12:05
 * @LastEditTime: 2020-05-03 11:37:31
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


//暴力解法
int maxSubArray(vector<int>& nums)
{
    int len=nums.size();
    int MAX=nums[0];

    for(int i=0;i<len;i++)
    {
        int sub=0;
        for(int j=i;j<len;j++)
        {
            sub+=nums[j];
            if(sub>MAX)
            {
                MAX=sub;
            }
        }
    }
    return MAX;
}

//动态规划法
/*
dp[i]表示nums中以nums[i]结尾的最大子序和
dp[i]=max(dp[i-1]+nums[i],nums[i]);
dp[i]时当前数字，要么是与前面的最大子序和的和

*/
int MaxSubArrayDongTai(vector<int>& nums)
{
    int result=INT_MIN;
    int numSize=int(nums.size());
    vector<int> dp(numSize);
    dp[0]=nums[0];
    result=dp[0];
    for(int i=1;i<numSize;i++)
    {
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        result=max(result,dp[i]);
    }
    return result;
}

/*
贪心法

从左向右迭代，一个个数字加过去，如果sum<0,重新开始找子序串

*/
int maxSubArrayTanXin(vector<int>& nums)
{
    int result=INT_MIN;
    int numSize=int(nums.size());
    int sum=0;
    for(int i=0;i<numSize;i++)
    {
        sum+=nums[i];
        result=max(result,sum);
        if(sum<0)
        {
            sum=0;
        }
    }
    return result;
}
/*
分治法
*/
int maxSubArrayFenZhi(vector<int>& nums)
{
    
}

int main()
{
    vector<int> res={-2,1,-3,4,-1,2,1,-5,4};
    int result=maxSubArray(res);
    return 0;
}