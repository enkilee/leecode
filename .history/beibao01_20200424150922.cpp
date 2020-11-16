/*
 * @Author: your name
 * @Date: 2020-04-24 15:05:53
 * @LastEditTime: 2020-04-24 15:09:22
 * @LastEditors: Please set LastEditors
 * @Description: 背包问题1
 * @FilePath: \leecode\beibao01.cpp
 * 
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。
输入样例
个数 容量
4    5
1    2
2    4
3    4
4    5
输出样例：
8
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;


/*
f[i][j] 表示只看前i个物品，总体积是j的情况下，总价值最大是多少
result=max(f[n][0-V])

*/
int main()
{
   
    return 0;
}