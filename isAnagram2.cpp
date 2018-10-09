class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }
        int book[26] = {0};
        for(char i : s)
        {
            book[i-'a']++;
        }
        int check[26] = {0};
        for(char i : t)
        {
            check[i-'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(book[i] != check[i])
            {
                return false;
            }
        }
        return true;
    }
};