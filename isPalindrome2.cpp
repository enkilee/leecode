class Solution {
public:
bool isPalindrome(string s) 
{        
    if(s.empty()) return true;        
    transform(s.begin(),s.end(),s.begin(),::tolower);//大写字母转为小写字母        
    int i = 0;        
    int j = s.size() - 1;        
    while(i < j)        
    {            
        if(!isalnum(s[i])) i++;            
        else if(!isalnum(s[j]))  j--;            
        else if(s[i]!=s[j]) return false;            
        else             
        {               
            i++;                
            j--;            
        }       
    }       
    return true;  
}
};