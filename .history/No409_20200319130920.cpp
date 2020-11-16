/*
 * @Author: your name
 * @Date: 2020-03-19 13:04:31
 * @LastEditTime: 2020-03-19 13:09:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\409.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;


int longestPalindrome(string s) 
{
    int ans;
    unordered_map<char,int> res;
    for(auto c:s)
    {
        ++res[c];
    }
    for(auto w:res)
    {
        if(w.second&1)
            ans+=w.second-1;
        else
            ans+=w.second;    
    }
    return ans<s.size()?ans+1:ans;
}

int main()
{
    string test="abbbbbcccdd";
    int ans=longestPalindrome(test);
    cout<<ans<<endl;
    return 0;
}



