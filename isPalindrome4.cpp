class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);  
        string ss;
        for(int i = 0;i < s.size();i++){
            if( isalpha(s[i]) || isdigit(s[i]) ){
                ss += s[i];
            }
        }
        s= ss;
        reverse(ss.begin(),ss.end());
        if(s==ss)
            return true;
        else 
            return false;
    }
};