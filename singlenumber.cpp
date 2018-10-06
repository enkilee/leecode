/*
如果存在一个只出现一次的数字，那么该数组所有的元素异或结果大于0！！！


*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for (int i = 0; i < nums.size(); ++i)
        {
            result ^= nums[i];
        }
        return result;
    }
};