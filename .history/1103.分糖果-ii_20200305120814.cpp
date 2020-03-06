/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people,0);
        int index=1; //数量从1开始
        while(candies>0)
        {
            for(int i=0;i<result.size();i++)
            {
                if(candies<index)
                {
                    result[i]=result[i]+candies;
                    candies=0;
                    break;
                }
                result[i]=result[i]+index;
                candies=candies-index;
                index++;
            }
        }
        return result;
    }
};


// @lc code=end

