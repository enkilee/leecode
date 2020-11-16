/*
 * @Author: your name
 * @Date: 2020-04-06 11:25:12
 * @LastEditTime: 2020-04-06 15:52:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no72.cpp
 * 编辑距离
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
            D[i][j]=min({left,down,left_down});

using namespace std;


int minDistance(string word1, string word2) 
{
    int n = word1.length();
    int m = word2.length();
    //某字符串为空
    if(n*m==0)
    {
        return m+n;
    }
    //DP数组
    int D[n+1][m+1];
    //边界状态初始化
    for(int i=0;i<n+1;i++)
    {
        D[i][0]=1;
    }
    for(int j=0;j<m+1;j++)
    {
        D[0][j]=1;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            int left=D[i-1][j]+1;
            int down=D[i][j-1]+1;
            int left_down=D[i-1][j-1];
            if(word1[i-1]!=word2[j-1])
            {
                left_down+=1;
            }
            D[i][j]=min({left,down,left_down});
        }
    }
    return D[n][m];
}
int main()
{
    string word1="intention";
    string word2="execution";
    int res=minDistance(word1,word2);
    cout<<res<<endl;
    return 0;
}