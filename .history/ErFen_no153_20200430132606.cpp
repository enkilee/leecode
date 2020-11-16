/*
* @Author: your name
* @Date: 2020-04-29 15:40:00
 * @LastEditTime: 2020-04-30 13:26:05
 * @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecode\no153.cpp

假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。
你可以假设数组中不存在重复元素。

*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

/*
所有变化点左侧元素 > 数组第一个元素
所有变化点右侧元素 < 数组第一个元素

*/
int findMin(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int left = 0, right = nums.size() - 1;
    if (nums[right] > nums[0])
    {
        return nums[0];
    }

/*
首先是while循环里的细节问题。

这里的循环不变式是left < right, 并且要保证  左闭右开  区间里面始终套住最小值。

中间位置的计算：mid = left + (right - left) / 2
这里整数除法是向下取整的地板除，mid更靠近left，
再结合while循环的条件left < right，
可以知道left <= mid，mid < right，
即在while循环内，mid始终小于right。

因此在while循环内，nums[mid]要么大于要么小于nums[right]，不会等于。

这样else {right = mid;}这句判断可以改为更精确的
else if (nums[mid] < nums[right]) {right = mid;}。

再分析一下while循环退出的条件。

如果输入数组只有一个数，左右边界位置重合，left == right，不会进入while循环，直接输出。

如果输入数组多于一个数，循环到最后，会只剩两个数，nums[left] == nums[mid]，以及nums[right]，
这里的位置left == mid == right - 1。

如果nums[left] == nums[mid] > nums[right]，则左边大、右边小，
需要执行left = mid + 1，使得left == right，左右边界位置重合，循环结束，
nums[left]与nums[right]都保存了最小值。

如果nums[left] == nums[mid] < nums[right]，则左边小、右边大，
会执行right = mid，使得left == right，左右边界位置重合，循环结束，
nums[left]、nums[mid]、nums[right]都保存了最小值。

*/
    while (left <= right)
    {                                        /* 循环不变式，如果left == right，则循环结束 */
        int mid = left + (right - left) / 2; /* 地板除，mid更靠近left */
        if (nums[mid] > nums[right])
        {                   /* 中值 > 右值，最小值在右半边，收缩左边界 */
            left = mid + 1; /* 因为中值 > 右值，中值肯定不是最小值，左边界可以跨过mid */
        }
        else if (nums[mid] < nums[right])
        {                /* 明确中值 < 右值，最小值在左半边，收缩右边界 */
            right = mid; /* 因为中值 < 右值，中值也可能是最小值，右边界只能取到mid处 */
        }
    }
    return nums[left]; /* 循环结束，left == right，最小值输出nums[left]或nums[right]均可 */
}


// 找最大值
int findMax(vector<int>& nums)
{
    int left=0;
    int right=nums.size()-1;
    while(left<right)
    {
        int mid=left+(right-left+1)/2; /* 先加一再除，mid更靠近右边的right */
        if(nums[left]<nums[mid])
        {
            left=mid;
        }
        else if(nums[left]>nums[mid])
        {
            right=mid-1;
        }
    }
    /* 最大值向右移动一位就是最小值了（需要考虑最大值在最右边的情况，右移一位后对数组长度取余） */
    return nums[(right+1)%nums.size()];
}
int main()
{
    vector<int> res={4,5,6,7,0,1,2};
    int result=findMin(res);
    return 0;
}