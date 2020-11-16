/*
* @Author: your name
* @Date: 2020-03-13 17:15:47
 * @LastEditTime: 2020-03-13 17:17:17
 * @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecode\no169.cpp
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

/*



方法一：哈希表
算法
我们使用哈希映射（HashMap）来存储每个元素以及出现的次数。对于哈希映射中的每个键值对，键表示一个元素，值表示该元素出现的次数。

我们用一个循环遍历数组 nums 并将数组中的每个元素加入哈希映射中。在这之后，我们遍历哈希映射中的所有键值对，返回值最大的键。我们同样也可以在遍历数组 nums 时候使用打擂台的方法，维护最大的值，这样省去了最后对哈希映射的遍历。
*/
int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }




int majorityElement(vector<int> &nums)
{
    int len = nums.size();
    int count = 0, candidate;
    for (int i = 0; i < len; i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
        }
        if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main()
{

    return 0;
}