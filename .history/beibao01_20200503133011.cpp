/*
 * @Author: your name
 * @Date: 2020-04-24 15:05:53
 * @LastEditTime: 2020-04-24 15:46:22
 * @LastEditors: Please set LastEditors
 * @Description: 背包问题1
 * @FilePath: \leecode\beibao01.cpp
 * 
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。
输入样例
数量 容积 
4    5
体积 价值
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

f[i][j]：
1、不选第i个，f[i][j]=f[i-1][j]
2、选第i个，f[i][j]=f[i-1][j-v[i]]+w[i]
f[i][j]=max(1,2)

*/

const int N=1010;

int n,m;
int f[N][N];
int f1[N];
int v[N],w[N];

int beibao01(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            // j要小于第i个物品的体积,就不能选这个物品，所以大于的时候才可以选
            if(j>=v[i])
            {
                f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
            }
        }
    }
    
    int res=0;
    for(int i=0;i<=m;i++)
    {
        res=max(res,f[n][i]);
    }
    cout<<res<<endl;
}

int beibao01youhua(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            f1[j]=max(f1[j],f1[j-v[i]]+w[i]);
        }
    }
    return f1[m];
}

int main()
{
    n=4,m=5;
    v[0]=4,w[0]=5;
    v[1]=1,w[1]=2;
    v[2]=2,w[2]=4;
    v[3]=3,w[3]=4;
    v[4]=4,w[4]=5;
    int res=beibao01(n,m);
    return 0;
}