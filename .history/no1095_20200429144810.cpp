/*
 * @Author: your name
 * @Date: 2020-04-29 14:16:50
 * @LastEditTime: 2020-04-29 14:48:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no1095.cpp
 
 这个方法的正确性在于我们二分的目标是相邻位置数的差值，
 我们每次判断的是 mountainArr.get(mid + 1) - mountainArr.get(mid) 与 0 的大小关系。
 这个差值组成的数组保证了单调递增的部分差值均为正数，单调递减的部分差值均为负数，
 整个数组呈现 [正数，正数，正数，...，负数，负数] 这样前半部分均为正数，
 后半部分均为负数的性质，满足单调性，因此我们可以使用二分查找。

以示例 1 为例，我们对整个数组进行差分，即除了第一个数每个数都减去前一个数得到新的数组，
最终我们得到 [1, 1, 1, 1, -2, -2]，整个差分数组满足单调性，可以应用二分法。

接下来我们只需要使用二分法在单调序列中找到目标值即可，注意二分法要使用两次，
为了编码简洁可以将二分法封装成函数。
 
 算法：
 
 先使用二分法找到数组的峰值。

在峰值左边使用二分法寻找目标值。

如果峰值左边没有目标值，那么使用二分法在峰值右边寻找目标值。

 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class MountainArray
{
    
}

int binary_search(MountainArray &mountain, int target, int l, int r, int key(int)) {

}


int main()
{
   
    return 0;
}

