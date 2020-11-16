/*
 * @Author: your name
 * @Date: 2020-05-03 13:19:24
 * @LastEditTime: 2020-05-03 13:21:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\ErFenTemplate.cpp
 * 
 * 二分的模板
 * 
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;


//基础
int search(vector<int>& nums,int target)
{
    int lo=0,hi=nums.size()-1,mid=0;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        if(nums[mid]<target)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return -1;
}


int main()
{
   
    return 0;
}