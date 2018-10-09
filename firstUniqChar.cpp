
class Solution {
public:
    int firstUniqChar(string s) {
        int hashTable[26];
        memset(hashTable, -1, sizeof(hashTable));
        for(int i=0; i<s.length(); i++) {
            if (hashTable[s[i] - 'a'] > -1) {           
                hashTable[s[i] - 'a'] = -2;
            } else if (hashTable[s[i] - 'a'] == -1) {
                hashTable[s[i] - 'a'] = i;
            }
        }
        
        int ret = -1;
        for(int i=0; i<26; i++) {
            if(hashTable[i] >= 0) {
                if(ret<0 || ret>hashTable[i]) {
                    ret = hashTable[i];
                }
            }
        }
        return ret;
    }
};