/*
 * @Author: your name
 * @Date: 2020-03-17 10:50:10
 * @LastEditTime: 2020-03-17 11:12:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no1160.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

void testunorderedmap(string chars)
{
    unordered_map<char,int> chars_cnt;
    for(char c:chars)
    {
        ++chars_cnt[c];
    }
    for(auto x:chars_cnt)
    {
        cout<<" "<<x.first<<" : "<<x.second<<endl;
    }
}

void testmap(string chars)
{
    map<char,int> chars_cnt;
    for(char c:chars)
    {
        ++chars_cnt[c];
    }
    for(auto x:chars_cnt)
    {
        cout<<" "<<x.first<<" : "<<x.second<<endl;
    }
}
int countCharacters(vector<string>& words, string chars) 
{
    
}
int main()
{
    
    return 0;
}