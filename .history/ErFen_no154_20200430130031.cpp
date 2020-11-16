/*
 * @Author: your name
 * @Date: 2020-04-30 12:48:15
 * @LastEditTime: 2020-04-30 13:00:31
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
/*

初始条件是左闭右闭区间，right = nums.size() - 1，
那么能否将while循环的条件也选为左闭右闭区间left <= right？

可以的，代码如下：

*/
int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {                         // 循环的条件选为左闭右闭区间left <= right
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[right]) {             // 注意是当中值大于等于右值时，
                left = mid + 1;                         // 将左边界移动到中值的右边
            } else {                                    // 当中值小于右值时
                right = mid;                            // 将右边界移动到中值处
            }
        }
        return nums[right];                             // 最小值返回nums[right]
    }

/*
这道题还有其它解法：
始终将nums[mid]与最右边界的数进行比较，
相当于在每次裁剪区间之后始终将最右边的数附在新数组的最右边。

*/

int findMin(vector<int>& nums) {
        int right_boundary = nums[nums.size() - 1];
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > right_boundary) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }



/*
或者在处理了第一种情况之后，始终将nums[mid]与最左边界的数nums[0]进行比较，
即相当于在每次裁剪区间之后始终将最左边的数附在新数组的最左边，再不断处理情况2及情况3。
*/

int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[0] < nums[right])
            return nums[left];
        while (left < right) { 
            int mid = left + (right - left) / 2; 
            if (nums[0] > nums[mid]) 
                right = mid; 
            else 
                left = mid + 1; 
        } 
        return nums[left];
    }

int main()
{
   
    return 0;
}