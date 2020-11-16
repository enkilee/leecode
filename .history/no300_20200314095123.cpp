/*
 * @Author: your name
 * @Date: 2020-03-14 09:32:24
 * @LastEditTime: 2020-03-14 09:51:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no300.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int max_element(vector<int>& dp)
{
    int len=dp.size();
    int max=0;
    for(int i=0;i<len;i++)
    {
        if(dp[i]<dp[i+1])
        {
            max=dp[i+1];
        }
        else
        {
            max=dp[i];
        }
    }
    return max;
}


int lengthOfLTS(vector<int>& nums)
{
    int len=nums.size();
    vector<int> dp(len,0);
    for(int i=0;i<len;i++)
    {
        dp[0]=1;
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int maxe=max_element(dp);
    return maxe;
}



int main()
{
    vector<int> num={10,9,2,5,3,7,101,18};
    int res=lengthOfLTS(num);
    cout<<res<<endl;
    return 0;
}