/*
* @Author: your name
* @Date: 2020-05-03 13:19:24
* @LastEditTime: 2020-05-03 13:24:44
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
int search(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1, mid = 0;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            return mid;
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
    return -1;
}
/*
1、为啥是 lo = mid + 1,hi = mid - 1 而不是 lo = mid, hi = mid 呢？
看循环条件 while(lo <= hi) 可知，当 lo 和 hi 差值为 1 或 0 的时候仍然会继续循环，
此时 mid 的值就不更新了，为了防止 lo 和 hi 也不更新从而死循环，所以这里要 + 1 和 -1。

2、这个基础二分模板的优势和弊端是啥呢？
好处是对于「有序数组查找目标值」很方便呢！
坏处是局限性太强，对于其他二分问题就很鸡肋，比如本题查找峰值，
需要在原模板基础上加上特殊的条件分支以及各种边界判断，
于是提交一次错一次，面向测试编程哈哈哈，最后终于终于把下标调整对了！
可下一次做的时候还要从头再错一遍。。。S。。A。。D。。。。

*/

//万能二分模板
/*
代码中「查找峰顶」用的是「万能二分模板」
找到峰顶后在两段「有序数组中查找目标值」用的是上面介绍的「基础二分模板」
（当然也可以用万能模板啦，万能模板就是很万能>o <）

*/
class MountainArray
{
public:
    int get(int index);
    int length();

private:
    int index;
};
int binSearch(MountainArray mountainArr, int lo, int hi, int target, bool asc)
{
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int midVal = mountainArr.get(mid);

        if (midVal == target)
        {
            return mid;
        }
        if (midVal < target)
        {
            lo = asc ? mid + 1 : lo;
            hi = asc ? hi : mid - 1;
        }
        else
        {
            hi = asc ? mid - 1 : hi;
            lo = asc ? lo : mid + 1;
        }
    }
    return -1;
}

int findInMountainArray(int target, MountainArray mountainArr)
{
    // 先找到峰顶索引 peakIdx
    int lo = 0, hi = mountainArr.length() - 1;
    while (lo + 1 < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int midVal = mountainArr.get(mid);

        if (midVal > mountainArr.get(mid - 1))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    int peakIdx = mountainArr.get(lo) > mountainArr.get(hi) ? lo : hi;
    // 根据峰顶将山脉数组分为「升序数组」和「降序数组」两段，分别进行二分查找
    int idx = binSearch(mountainArr, 0, peakIdx, target, true);
    return idx != -1 ? idx : binSearch(mountainArr, peakIdx + 1, mountainArr.length() - 1, target, false);
}

int main()
{

    return 0;
}