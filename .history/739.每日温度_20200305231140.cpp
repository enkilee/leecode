/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 * 就是：找下一个比当前数字大的数字的距离
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result;
        for (int i = 0; i < T.size(); i ++) {
            int day = 0;
            for (int j = i + 1; j < T.size(); j ++) {
                if (T[j] > T[i]) {
                    day = j - i;
                    break;
                }
            }
            result.push_back(day);
        }
        return result;
    }
};
// @lc code=end

