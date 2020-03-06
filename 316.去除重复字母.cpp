/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 * 
 *
1、遍历字符串里的字符，如果读到的字符的 ASCII 值是升序，依次存到一个栈中；
2、如果读到的字符在栈中已经存在，这个字符我们不需要；
3、如果读到的 ASCII 值比栈顶元素严格小，看看栈顶元素在后面是否还会出现，如果还会出现，
则舍弃栈顶元素，而选择后出现的那个字符，这样得到的字典序更小。
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int ssize = s.size();
        if(ssize<2)
            return s;
        bool used[26];
        for(bool &i:used)
        {
            i=false;
        }
        int lastAppearIndex[26];
        for(int i=0;i<ssize;i++)
        {
            lastAppearIndex[s[i]-'a']=i;
        }
        stack<char> st;
        for(int i=0;i<ssize;i++)
        {
            if(used[s[i]-'a'])
                continue;
            while(!st.empty()&& st.top()>s[i] && lastAppearIndex[st.top()-'a']>=i)
            {
                char top = st.top();
                st.pop();
                used[top-'a']=false;
            }
            st.push(s[i]);
            used[s[i]-'a']=true;
        }
        string res;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

