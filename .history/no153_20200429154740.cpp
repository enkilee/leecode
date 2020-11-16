/*
 * @Author: your name
 * @Date: 2020-04-29 15:40:00
 * @LastEditTime: 2020-04-29 15:47:40
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

*/
int findMin(vector<int>& nums)
{

}

int main()
{
   
    return 0;
}