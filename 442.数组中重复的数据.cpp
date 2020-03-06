/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int v:nums)
        {
            v=abs(v);
            if(nums[v-1]<0)
                res.push_back(v);
            else
            {
                nums[v-1]=-nums[v-1];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            int temp=abs(nums[i]);
            if(nums[temp-1]<0)
                res.push_back(temp);
            nums[temp-1]=-nums[temp-1];
        }
        return res;
    }
};
// @lc code=end

