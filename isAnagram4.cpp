class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> map1, map2;
        for (int i = 0; i < s.size(); ++i) {
            map1[s[i]]++;
            map2[t[i]]++;
        }

        for (auto it : map1) {
            if (map2[it.first] != it.second)
                return false;
        }

        return true;
    }
};