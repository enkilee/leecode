/*
 * @Author: your name
 * @Date: 2020-04-24 10:08:46
 * @LastEditTime: 2020-04-24 12:31:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\mianshi08.11.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

static constexpr int mod = 1000000007;
static constexpr int coins[4] = {25, 10, 5, 1};

int waysToChange(int n)
{
    vector<int> f(n+1);
    f[0]=1;
    for(int c=0;c<4;c++)
    {
        int coin=coins[c];
        for(int i=coin;i<=n;i++)
        {
            f[i]=(f[i]+f[i-coin])%mod;
        }
    }
    return f[n];
}

int waysToChangeUseMath(int n)
{
    int ans=0;
    for(int i=0;i*25<=n;i++)
    {
        int rest=n-i*25;
        int a=rest/10;
        int b=rest%10/5;
        ans=(ans+(long long)(a+1)*(a+b+1)%mod)%mod;
    }
    return ans;
}

int main()
{
   
    return 0;
}