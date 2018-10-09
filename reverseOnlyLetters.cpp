class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l=0;
        int r=S.size()-1;
        while(l<r)
        {
            if(((S[l]>='A'&&S[l]<='Z')||(S[l]>='a'&&S[l]<='z'))&&((S[r]>='A'&&S[r]<='Z')||(S[r]>='a'&&S[r]<='z')))
            {
                swap(S[l++],S[r--]);
            }
            else if(!((S[l]>='A'&&S[l]<='Z')||(S[l]>='a'&&S[l]<='z'))&&((S[r]>='A'&&S[r]<='Z')||(S[r]>='a'&&S[r]<='z')))
            l++;                    //��߲�����ĸ���������һ������
            else if(((S[l]>='A'&&S[l]<='Z')||(S[l]>='a'&&S[l]<='z'))&&!((S[r]>='A'&&S[r]<='Z')||(S[r]>='a'&&S[r]<='z')))
            r--;                   //�ұ߲�����ĸ���ұ�����һ������
            else                       //��������ĸ�������һ�Ҽ�һ��
            {
                l++;
                r--;
            }
        }
        return S;
    }
};