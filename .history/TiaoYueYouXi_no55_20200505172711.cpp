/*
 * @Author: your name
 * @Date: 2020-05-05 17:17:37
 * @LastEditTime: 2020-05-05 17:27:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no55.cpp
 * 
 * 


 */

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;



/*
以题目中的示例一

[2, 3, 1, 1, 4]
为例：

我们一开始在位置 0，可以跳跃的最大长度为 2
，因此最远可以到达的位置被更新为 2；
,
我们遍历到位置 1，由于 1 <2，因此位置 1 可达。
我们用 1 加上它可以跳跃的最大长度 3，
将最远可以到达的位置更新为 4。
由于 4 大于等于最后一个位置 4，
因此我们直接返回 True。



*/
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

/*


解题思路：
如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
如果可以一直跳到最后，就成功了。
*/

bool canJump2(vector<int>& nums)
{
    int k=0;
    for(int i=0;i<nums.size();i++)
    {
        if(i>k)
            return false;
        k=max(k,i+nums[i]);    
    }
    return true;
}

int main()
{
   
    return 0;
}