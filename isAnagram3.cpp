class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(char c:s)
        {
            count1[c-'a']++;
        }
        for(char c:t)
        {
            count2[c-'a']++;
        }
        return count1==count2;
    }
};