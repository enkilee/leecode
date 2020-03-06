/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char> sta(s.size());
        for(int i=0;i<s.size();i++)
        {
            if(sta.empty())
                sta.push(s[i]);
            else if(s[i]==')'&&sta.top()=='('
            || s[i]==']'&&sta.top()=='['
            || s[i]=='}'&&sta.top()=='{'   )
                sta.pop();
            else
            {
                return false;
            }
        }    
        if(sta.empty())
        {
            return true;
        }
    }
};
// @lc code=end

