/*
 * @Author: your name
 * @Date: 2020-05-03 15:34:37
 * @LastEditTime: 2020-05-03 16:23:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\beibao02.cpp
 * 
 * 
有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。

第 i 种物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，
分别表示第 i 种物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例

种数  容积
4     5

体积  价值
V     W
1     2
2     4
3     4
4     5
输出样例：
10
 */


/*
f[i]表示 总体积是i的情况下，最大价值是多少
max(f[0...m])  m:容量

for(int i=0;i<n;i++)
{ 
    //从小到大枚举：
    for(int j=v[i];j<=m;j++)
    {
        //f[j-v[i]] 考虑前i个，包括第i个，
        体积是J-V[I],可能已经包含了若干个第I个物品
        f[j]=max(f[j],f[j-v[i]]+w[i])
    }
}
    数学归纳法：
    1、假设考虑前i-1个物品后，所有的f[j]都是正确的
    2、来证明：考虑完第i个物品后，所有的f[j]也都是正确的

    对于某个j而言，如果最优解包含k个v[i]:
    f[j-k*v[i]]  
    f[j-(k-1)*v[i]-v[i]]+w[i] 包含1个v[i]
    ...
    f[j] f[j-v[i]]+w[i]



    //如果从打大到小进行枚举：
    for(int j=m;j>=v[i];j--)
    {
        for(int k=0;k*v[i]<=j;k++)
        {
            f[j]=max(f[j],f[j-k*v[i]]+k*w[i])
        }
    }
}


*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
const int N=1010;

int n,m;
int f[N][N];
int f1[N];
int v[N],w[N];

int beibaoWanQuan(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=v[i];j<=m;j++)
        {
            //f[j-v[i]] 考虑前i个，包括第i个，
            //体积是J-V[I],可能已经包含了若干个第I个物品
            f1[j]=max(f1[j],f1[j-v[i]]+w[i]);
        }
    }
}

int main()
{
    n=4,m=5;
    v[0]=4,w[0]=5;
    v[1]=1,w[1]=2;
    v[2]=2,w[2]=4;
    v[3]=3,w[3]=4;
    v[4]=4,w[4]=5;
    int res=beibaoWanQuan(n,m);
    return 0;
    return 0;
}