/*
* @Author: your name
* @Date: 2020-04-29 15:54:26
* @LastEditTime: 2020-04-29 16:06:09
* @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecode\no33.cpp

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。


输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int search(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        //很有意思的方法：
        /*
对于旋转数组 nums = [4,5,6,7,0,1,2]
首先根据 nums[0] 与 target 的关系判断 target 是在左段还是右段。

例如 target = 5, 目标值在左半段，因此在 [4, 5, 6, 7, inf, inf, inf] 这个有序数组里找就行了；
例如 target = 1, 目标值在右半段，因此在 [-inf, -inf, -inf, -inf, 0, 1, 2] 这个有序数组里找就行了。
    */

        // 先根据 nums[0] 与 target 的关系判断目标值是在左半段还是右半段
        if (target >= nums[0])
        {
            // 目标值在左半段时，若 mid 在右半段，则将 mid 索引的值改成 inf
            if (nums[mid] < nums[0])
            {
                nums[mid] = INT_MAX;
            }
        }
        else
        {
            // 目标值在右半段时，若 mid 在左半段，则将 mid 索引的值改成 -inf
            if (nums[mid] >= nums[0])
            {
                nums[mid] = INT_MIN;
            }
        }
        if (nums[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
}

//  方法三：先根据 nums[mid] 与 nums[lo] 的关系判断 mid 是在左段还是右段，
//  接下来再判断 target 是在 mid 的左边还是右边，从而来调整左右边界 lo 和 hi。

int searchMethod3(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // 4 5 6 7 0 1 2
        // 先根据 nums[mid] 与 nums[lo] 的关系判断 mid 是在左段还是右段
        if (nums[mid] >= nums[lo])
        {
            // 再判断 target 是在 mid 的左边还是右边，从而调整左右边界 lo 和 hi
            if (target >= nums[lo] && target < nums[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            if (target > nums[mid] && target <= nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> res = {4, 5, 6, 7, 0, 1, 2};
    int tar = 6;
    int result = searchMethod3(res, tar);
    return 0;
}