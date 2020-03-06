/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()<=2)
            return -1;
        int sum=0;
        int sumleft=0;
        int len=nums.size();
        for(int i=0;i<len;++i)
        {
            sum+=nums[i];
        }
        for(int i=0;i<len;++i)
        {
            if(sumleft*2+nums[i]==sum)
                return i;
            sumleft+=nums[i];
        }
        return -1;
    }
};
// @lc code=end

