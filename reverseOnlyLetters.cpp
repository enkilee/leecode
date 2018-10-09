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
            l++;                    //左边不是字母，左边做加一操作。
            else if(((S[l]>='A'&&S[l]<='Z')||(S[l]>='a'&&S[l]<='z'))&&!((S[r]>='A'&&S[r]<='Z')||(S[r]>='a'&&S[r]<='z')))
            r--;                   //右边不是字母，右边做减一操作。
            else                       //都不是字母，则左加一右减一。
            {
                l++;
                r--;
            }
        }
        return S;
    }
};