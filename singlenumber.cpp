/*
�������һ��ֻ����һ�ε����֣���ô���������е�Ԫ�����������0������


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