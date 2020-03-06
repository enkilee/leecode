/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        do
        {
            /* code */
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while (slow!=fast);
        
        int ptr1=0;
        int ptr2=slow;
        while (ptr1!=ptr2)
        {
            /* code */
            ptr1=nums[ptr1];
            ptr2=nums[ptr2];
        }
        return ptr1;
        
    }
};
// @lc code=end

