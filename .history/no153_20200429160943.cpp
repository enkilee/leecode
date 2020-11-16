/*
* @Author: your name
* @Date: 2020-04-29 15:40:00
* @LastEditTime: 2020-04-29 15:51:51
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


算法:

找到数组的中间元素 mid。
如果中间元素 > 数组第一个元素，我们需要在 mid 右边搜索变化点。
如果中间元素 < 数组第一个元素，我们需要在 mid 做边搜索变化点。

当我们找到变化点时停止搜索，当以下条件满足任意一个即可：
nums[mid] > nums[mid + 1]，因此 mid+1 是最小值。
nums[mid - 1] > nums[mid]，因此 mid 是最小值。


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

    while (left < right)
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

int main()
{

    return 0;
}