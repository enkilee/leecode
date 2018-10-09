class Solution {
public:
    bool isAnagram(string s, string t) {
        int m=s.size();
        int n=t.size();
        int sm[26]={0};
        int tn[26]={0};
        int flag = 1;
        for(int i=0;i<m;i++)
        {
            sm[s[i]-97]=sm[s[i]-97]+1;
        }
        for(int j=0;j<n;j++)
        {
            tn[t[j]-97]=tn[t[j]-97]+1;
        }
        for (int l=0;l<26;l++)
        {
            if(sm[l]!=tn[l])
                flag=0;
        }
        if(flag)
        {return true;}
        else
        {return false;}
        
    }
};