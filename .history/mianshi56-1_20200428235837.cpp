/*
 * @Author: your name
 * @Date: 2020-04-28 23:49:47
 * @LastEditTime: 2020-04-28 23:58:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\mianshi56-1.cpp
 * 
 * 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 * 
 * 输入：nums = [4,1,4,6]
   输出：[1,6] 或 [6,1]
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;


//最简单的办法，map
vector<int> singleNumber(vector<int>& nums)
{
    vector<int> res;
    map<int,int> m;
    for(auto i:nums)
    {
        m[i]++;
    }
    for(auto i:m)
    {
        if(i.second==1)
        {
            res.emplace_back(i.first);
        }
    }
    return res;
}
int main()
{
   
    return 0;
}