/*
 * @Author: your name
 * @Date: 2020-03-09 15:13:15
 * @LastEditTime: 2020-05-03 13:10:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\121.买卖股票的最佳时机.cpp
 */
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                ans=max(ans,prices[j]-prices[i]);
            }
        }
        return ans;
    }
};

/*
我们来假设自己来购买股票。随着时间的推移，每天我们都可以选择出售股票与否。
那么，假设在第 i 天，如果我们要在今天卖股票，那么我们能赚多少钱呢？

显然，如果我们真的在买卖股票，我们肯定会想：如果我是在历史最低点买的股票就好了！
太好了，在题目中，我们只要用一个变量记录一个历史最低价格 minprice，我们就可以假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice。

因此，我们只需要遍历价格数组一遍，记录历史最低点，然后在每一天考虑这么一个问题：

如果我是在历史最低点买进的，那么我今天卖出能赚多少钱？
当考虑完所有天数之时，我们就得到了最好的答案。



*/
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                ans=max(ans,prices[j]-prices[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

