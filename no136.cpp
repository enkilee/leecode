/*
 * @Author: your name
 * @Date: 2020-04-28 23:46:46
 * @LastEditTime: 2020-04-28 23:47:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no136.cpp
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int singleNumber(vector<int> & nums)
{
    int res=0;
    for(int i=0;i<nums.size();i++)
    {
        res ^=nums[i];
    }
    return res;
}

int main()
{
    vector<int> test={2,2,1};
    int res=singleNumber(test);
    return 0;
}