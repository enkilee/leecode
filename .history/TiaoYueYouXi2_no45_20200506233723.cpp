/*
 * @Author: your name
 * @Date: 2020-05-05 17:32:54
 * @LastEditTime: 2020-05-06 23:33:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\TiaoYueYouXi2_no45.cpp
 * 

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;


// v1
/*
如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
11. 可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。

如果从这个 起跳点 起跳叫做第 1 次 跳跃，那么从后面 3 个格子起跳 都 可以叫做第 2 次 跳跃。

所以，当一次 跳跃 结束时，从下一个格子开始，到现在 能跳到最远的距离，都 是下一次 跳跃 的 起跳点。
31. 对每一次 跳跃 用 for 循环来模拟。
32. 跳完一次之后，更新下一次 起跳点 的范围。
33. 在新的范围内跳，更新 能跳到最远的距离。

记录 跳跃 次数，如果跳到了终点，就得到了结果。
*/
int jumpV1(vector<int>& nums)
{
    int start=0;
    int result=0;
    int end=1;
    while(end<nums.size())
    {
        int maxStep=0;
        for(int i=0;i<end;i++)
        {
            maxStep=max(maxStep,nums[i]+i);
        }
        start=end;  // 下一次起跳点范围开始的格子
        end=maxStep+1;  // 下一次起跳点范围结束的格子
        result++;
    }
    return result;
}
//v1优化：
/*


*/
int jumpV2(vector<int>& nums) 
{
    int end=0;//初始化边界
    int maxPosition;
    int steps=0;
    //这里必须-1，因为=0的时候，step加了1步
    for(int i=0;i<nums.size()-1;i++)
    {
        maxPosition=max(maxPosition,nums[i]+i);
        if(i==end)//遇到边界，就更新边界，并且步数加一
        {
            end=maxPosition;
            steps++;
        }
    }
    return steps;
}

int main()
{
    vector<int> test= {2,3,1,1,4};
    int res=jumpV1(test);
    return 0;
}