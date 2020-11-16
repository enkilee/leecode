/*
* @Author: your name
* @Date: 2020-04-28 23:49:47
 * @LastEditTime: 2020-04-28 23:59:52
 * @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecode\mianshi56-1.cpp
* 
* 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
* 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
* 
* 输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

//最简单的办法，map
vector<int> singleNumber(vector<int> &nums)
{
    vector<int> res;
    map<int, int> m;
    for (auto i : nums)
    {
        m[i]++;
    }
    for (auto i : m)
    {
        if (i.second == 1)
        {
            res.emplace_back(i.first);
        }
    }
    return res;
}

/// 异或的办法
vector<int> singleNumbersYiHuo(vector<int> &nums)
{
    int s = 0;
    for (int num : nums)
    {
        s ^= num;
    }
    //s是只出现一次的2个数字的^ 记做数字a,b
    //既然a,b 不一样，那么s肯定不是0，那么s的二进制肯定至少有1位（第n位）是1，只有0^1才等于1
    //所以a,b 在第n位，要么a是0，b是1 ，要么b是0，a是1    ---->A
    //s = 3 ^ 5; 0x0011 ^ 0x0101 = 0x0110 = 6
    //假设int是8位
    //-6  原码1000 0110
    //    反码1111 0001
    //    补码1111 0010
    //s & (-s)
    //  0000 0110
    //& 1111 0010
    //  0000 0010
    //所以k = s & (-s) 就是保留s的最后一个1，并且将其他位变为0  也就是s最后一个1是倒数第二位   --->B
    //根据A和B  我们可以将数组分为2组  将倒数第二位 为0的分为第一组
    int k = s & (-s);
    //1  0001  第一组
    //2  0010  第二组
    //1  0001  第一组
    //3  0011  第二组
    //2  0010  第二组
    //5  0101  第一组
    //第一组 1 1 5  第二组 2 3 2 这样我们就将2个只有一个的数 分到了2个数组里了
    vector<int> rs(2, 0);
    for (int num : nums)
    {
        if (num & k)
        {
            //第二组
            rs[0] ^= num;
        }
        else
        {
            //第一组
            rs[1] ^= num;
        }
    }
    return rs;
}

int main()
{

    return 0;
}