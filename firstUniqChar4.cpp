class Solution {
public:
    int firstUniqChar(string s) 
    {
        if(s.size()==0)
            return -1;
        int flag[26]={0};//出现次数
        int findFirstIdx[26];//第一次出现位置
        for(auto &i:findFirstIdx)
            i=-1;
        //遍历，记录出现次数和第一次出现位置
        for(int i=0;i<s.size();i++)
        {
            char c=s[i]-'a';
            flag[c]++;
            if(flag[c]==1)                
                findFirstIdx[c]=i;
        }
        //找第一个不重复字符
        //该方法适合原始字符串很大时候
        if(s.size()>26)
        {
            int uniqueIdx=INT_MAX;
            for(auto i=0;i<26;i++)
            {
                if(flag[i]==1 && findFirstIdx[i]<uniqueIdx)
                    uniqueIdx=findFirstIdx[i];
            }
            if(uniqueIdx==INT_MAX)
                return -1;
            else
                return uniqueIdx;
        }
        else
        {
            for(auto i=0;i<s.size();i++)
            {
                if(flag[s[i]-'a']==1)
                    return i;
            }
            return -1;
        }
    }
};