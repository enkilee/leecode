/*
* @Author: your name
* @Date: 2020-04-28 23:49:47
 * @LastEditTime: 2020-04-29 00:07:43
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

//异或+二分

/*

我们回到今天的这道题上来。如果我们对所有的数字进行异或，假设只出现一次的数字分别是
 pp 和 qq，那么最终的结果 p \oplus qp⊕q，此时我们不知道 pp 和 qq 分别是什么
 。但是如果我们能把 pp 和 qq 从 数组里面区分开来呢？假设我们知道了某个数 rr，rr
  是介于 pp 和 qq 之间，那么我们可以把整个数组分成两部分 —— a_{i}<=ra 
i<=r 或 a_{i}>ra 
i>r。并且，一个数组里有 pp，另一个数组里有 qq。那么对这两部分的数字分别求异或和，
结果就变成了 pp 和 qq 。完美！这样就把问题转换成了我们已经解决的问题上了！

我举个栗子来说一下上面的想法：
我们看下数组 [1,2,10,4,1,4,3,3]，我们知道 pp 和 qq 是 2 和 10。
中间的数字我们假设是 3，根据 a_{i}<=3a 
i
​	
 <=3 和 a_{i}>3a 
i
​	
 >3 划分成了[1,2,1,3,3] 和 [10,4,4]。这两个数组分别异或就是 2 和 10。

但是还没有解决，怎么找到 pp 和 qq 中间的数字 rr 呢？

二分！！！

为什么是二分呢？一个暴力的方法就是从数组最小的元素到最大的元素枚举所有可能的 rr，然后根据 a_{i}<=ra 
i
​	
 <=r 和 a_{i}>ra 
i
​	
 >r 化成两个数组，再看两个数组的异或和是不是都不为 0，如果是，那我们就找到了 rr。但是注意到，在枚举 rr 的时候，两个数组的异或和是否为0这个性质是单调的！

下图是从数组最小的元素到最大的元素枚举 rr 的过程。

为了更能体现出来单调的性质，我把 r=0r=0 和 r=11r=11 也加进来了。


简单来说，

如果当前左边的数组异或和为 00, 右边不为 00，说明当前枚举的 rr 小了；
如果当前左边的数组异或和不为 00, 右边也不为 00，说明当前枚举的 rr 是符合要求的，
左右数组异或的结果就是答案；
如果当前左边的数组异或和不为 00, 右边为 00，说明当前枚举的 rr 大了；
这就是单调的样子。所以可以二分。

记住，只要符合单调，就可以二分！！！

但是，你以为这完了吗？异或和为 00 其实并不代表 要找的元素不在这里面，因为有可能 00 只出现了 11 次！
 所以这种思路需要特判一下某个数为 00 的情况。


*/
vector<int> singleNumberYHEF(vector<int>& nums)
{
    vector<int> res;
    int sum=0,mmin=INT_MAX,mmax=INT_MIN,zeroCount=0;
    for(auto num:nums)
    {
        if(num==0)
        {
            zeroCount+=1;
        }
        mmin=min(mmin,num);
        mmax=max(mmax,num);
        sum ^=num;
    }
    // 需要特判一下某个数是0的情况。
        if (zeroCount == 1) {
            return res(sum,0);
        }

}

int main()
{

    return 0;
}