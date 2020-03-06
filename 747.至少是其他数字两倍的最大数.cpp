/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> sortedv=nums;
        sort(sortedv.begin(),sortedv.end());
        int index,last,pre=0;
        if(sortedv.nums()>=2)
        {
            last=sortedv[nums.size()-1];
            pre=sortedv[nums.size()-2];
        }
        else
        {
            return 0;
        }
        for(index;index<nums.size();++index)
        {
            if(last=nums[index])
                break;
        }
        if(last!=0&&pre==0)
            return index;
        if(last/pre>2||(last/pre==2&&last%pre>=0))
            return index;
        return -1;
    }
};
// @lc code=end

