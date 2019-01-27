class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        string n;
        for(auto c : s)
            if(isalnum(c))
                n += c;
        for(int i = 0; i < n.size()/2; ++i) {
            if(n[i] != n[n.size()-i-1])
                return false;
        }
        return true;
    }
};