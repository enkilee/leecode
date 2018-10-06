class Solution {
public:
    string reverseString(string s) {
        int l = s.size();
        int i = 0;
        int j = l-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};