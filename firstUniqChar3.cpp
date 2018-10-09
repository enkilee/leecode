class Solution {
public:
    int firstUniqChar(string s) {
		int table[26] = { 0 };

		for (int i = s.length() - 1;i >= 0;--i)
			++table[s[i] - 'a'];
		for (int i = 0;i < s.length();++i)
			if (table[s[i] - 'a'] < 2)return i;
		return -1;
    }
};