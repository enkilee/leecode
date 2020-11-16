/*
* @Author: your name
* @Date: 2020-03-13 17:15:47
 * @LastEditTime: 2020-03-13 17:18:24
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

/*
方法二：排序
思路

如果将数组 nums 中的所有元素按照单调递增或单调递减的顺序排序，那么下标为 \lfloor \dfrac{n}{2} \rfloor⌊ 
2
n
​	
 ⌋ 的元素（下标从 0 开始）一定是众数。
算法
对于这种算法，我们先将 nums 数组排序，然后返回上文所说的下标对应的元素。下面的图中解释了为什么这种策略是有效的。在下图中，第一个例子是 nn 为奇数的情况，第二个例子是 nn 为偶数的情况。
对于每种情况，数组下面的线表示如果众数是数组中的最小值时覆盖的下标，数组下面的线表示如果众数是数组中的最大值时覆盖的下标。对于其他的情况，这条线会在这两种极端情况的中间。对于这两种极端情况，它们会在下标为 \lfloor \dfrac{n}{2} \rfloor⌊ 
2
n
​	
 ⌋ 的地方有重叠。因此，无论众数是多少，返回 \lfloor \dfrac{n}{2} \rfloor⌊ 
2
n
​	
 ⌋ 下标对应的值都是正确的。
*/
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }


/*
方法三：随机化
因为超过 \lfloor \dfrac{n}{2} \rfloor⌊ 
2
n
​	
 ⌋ 的数组下标被众数占据了，这样我们随机挑选一个下标对应的元素并验证，有很大的概率能找到众数。

算法

由于一个给定的下标对应的数字很有可能是众数，我们随机挑选一个下标，检查它是否是众数，如果是就返回，否则继续随机挑选。
*/
int majorityElement(vector<int>& nums) {
        while (true) {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums)
                if (num == candidate)
                    ++count;
            if (count > nums.size() / 2)
                return candidate;
        }
        return -1;
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