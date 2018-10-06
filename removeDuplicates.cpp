//删除排序数组中的重复项

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = 0;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != nums[n])
                swap(nums[i], nums[++n]);
        return n + 1;
    }
};