class Solution {
public:
    int firstUniqChar(string s) 
    {
        if(s.size()==0)
            return -1;
        int flag[26]={0};//���ִ���
        int findFirstIdx[26];//��һ�γ���λ��
        for(auto &i:findFirstIdx)
            i=-1;
        //��������¼���ִ����͵�һ�γ���λ��
        for(int i=0;i<s.size();i++)
        {
            char c=s[i]-'a';
            flag[c]++;
            if(flag[c]==1)                
                findFirstIdx[c]=i;
        }
        //�ҵ�һ�����ظ��ַ�
        //�÷����ʺ�ԭʼ�ַ����ܴ�ʱ��
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