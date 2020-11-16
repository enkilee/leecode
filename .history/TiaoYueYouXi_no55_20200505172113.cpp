/*
 * @Author: your name
 * @Date: 2020-05-05 17:17:37
 * @LastEditTime: 2020-05-05 17:17:37
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no55.cpp
 * 
 * 解题思路：
如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
如果可以一直跳到最后，就成功了。


 */

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums)
{
    int n=nums.size();
    int rightmost=0;
    for(int i=0;i<n;i++)
    {
        if(i<=rightmost)
        {
            rightmost=max(rightmost,i+nums[i]);
            if(rightmost>=n-1)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
   
    return 0;
}