class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int leng=nums.size();
        for(int i=0;i<leng-k;i++)
        {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
        
    }
};