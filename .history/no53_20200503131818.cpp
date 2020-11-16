/*
 * @Author: your name
 * @Date: 2020-05-03 11:12:05
 * @LastEditTime: 2020-05-03 13:18:17
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
算法时间复杂度为O(n)，空间复杂度为O(n)
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
Kadane算法：在动态规划上进一步优化，
它使用一根指针保存以i为结尾的子数组最大值之和，
使用另一根指针保存迄今为止的子数组最大值之和。
算法时间复杂度为O（n）,空间复杂度为O(1)。代码非常漂亮优雅。
*/

int maxSubArrayWithKadane(vector<int>& nums)
{
    int len=nums.size();
    int max_ending_here,max_sub_sum=nums[0];
    for(int i=1;i<len;i++)
    {
        max_ending_here=max(max_ending_here+nums[i],nums[i]);
        max_sub_sum=max(max_ending_here,max_sub_sum);
    }
    return max_sub_sum;
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

int findMaxCrossingSubarray(vector<int>& nums,int left, int mid, int right)
{
    int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
}

int maxSubArrayHelper(vector<int>& nums,int left, int right)
{
    if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftSum = maxSubArrayHelper(nums, left, mid);
        //注意这里应是mid + 1，否则left + 1 = right时，会无线循环
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);
        int result = max(leftSum, rightSum);
        result = max(result, midSum);
        return result;
}

int maxSubArrayFenZhi(vector<int>& nums)
{
    //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        result = maxSubArrayHelper(nums, 0, numsSize - 1);
        return result;
}

int main()
{
    vector<int> res={-2,1,-3,4,-1,2,1,-5,4};
    int result=maxSubArray(res);
    return 0;
}