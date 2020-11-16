/*
* @Author: your name
* @Date: 2020-04-21 09:16:53
 * @LastEditTime: 2020-04-21 09:21:58
 * @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecodee:\Data Structures & algorithms Using C++\houjieCPP\no1248.cpp
* 
给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。

输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。

输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16

*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = (int)nums.size();
    int odd[n+2],ans=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]&1)
        {
            odd[++cnt]=1;
        }
    }
    odd[0]=-1;
    odd[++cnt]=n;
    for(int i=1;i+k<=cnt;++i)
    {
        ans+=(odd[i]-odd[i-1])*(odd[i+k]-odd[i+k-1]);
    }
    return ans;
}

int main()
{

    return 0;
}