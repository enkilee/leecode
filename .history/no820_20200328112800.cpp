/*
 * @Author: your name
 * @Date: 2020-03-28 11:23:57
 * @LastEditTime: 2020-03-28 11:28:00
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
    for(const string& word : words)
    {
        for(int k=1;k<word.size();k++)
        {
            good.erase(word.substr(k));
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
   
    return 0;
}