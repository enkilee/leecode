/*
 * @Author: your name
 * @Date: 2020-03-28 11:23:57
 * @LastEditTime: 2020-03-28 11:38:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no820.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>

using namespace std;

int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string> good(words.begin(),words.end());
    for(auto w:good)
    {
        cout<<w<<endl;
    }
    for(const string& word : words)
    {
        cout<<word<<endl;
        for(int k=1;k<word.size();k++)
        {
            good.erase(word.substr(k));
        }
        for(auto w:good)
        {
        cout<<w<<endl;
        }
    }
    
    int ans=0;
    for(const string& word:good)
    {
        ans+=word.size()+1;
    }
    return ans;
}


int main()
{
   vector<string> words={"time", "me", "bell"};
   int res=minimumLengthEncoding(words);
   cout<<res<<endl;
    return 0;
}