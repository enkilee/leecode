/*
 * @Author: your name
 * @Date: 2020-04-30 12:48:15
 * @LastEditTime: 2020-04-30 12:57:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\ErFen_no154.cpp
 * 

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int findMin(vector<int>& nums)
{
    int left=0;
    int right=nums.size()-1;
    while(left<right)
    {
        int mid = left+(right-left)/2;
        if(nums[mid]>nums[right])
        {
            left=mid+1;
        }
        else if(nums[mid]<nums[right])
        {
            right=mid;
        }
        else
        {
            right--;
        }
    }
    return nums[left];
}


int main()
{
   
    return 0;
}