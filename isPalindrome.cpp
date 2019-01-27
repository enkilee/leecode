class Solution {
public:
    bool isPalindrome(string s) {
    transform(s.begin(),s.end(),s.begin(),::tolower);
    if(s.empty())
        return true;
    int start=0;
    int end=s.length()-1;
    while(start<end)
    {
        if(!isAlphaNum(s[start]))
            start++;
        else if(!isAlphaNum(s[end]))
            end--;
        //若两个指针都指向字母/数字
        else if((s[start]-'a'+32)%32!= (s[end]-'a'+32)%32)
            return false;
        else
        {
            start++;
            end--;
        }
    }
        return true;
    }
    bool isAlphaNum(char& s)
    {        
        if(s>='a'&&s<='z') return true;        
        if(s>='A'&&s<='Z') return true;        
        if(s>='0'&&s<='9') return true;        
        return false;
    }

};