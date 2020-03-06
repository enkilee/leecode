/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int len=nums.size();
        int i=0,temp=0;
        for(i;i<len;i++)
        {
            temp=abs(nums[i])-1;
            if(nums[temp]>0)
                nums[temp]=-nums[temp];
        }
        for(i=0;i<len;i++)
        {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};
// @lc code=end

