/*
 * @Author: your name
 * @Date: 2020-03-17 10:50:10
 * @LastEditTime: 2020-03-17 11:23:06
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
vector<int> count(string &chars)
{
    vector<int> counter(26,0);
    for(char c:chars)
    {
        counter[c-'a']++;
    }
    return counter;
}
bool contains(vector<int> &charscount,vector<int> &wordcount)
{
    bool result;
    for(int i=0;i<26;++i)
    {
        if(charscount[i]<wordcount[i])
            return false;
    }
    return true;
}
int countCharacters(vector<string>& words, string chars) 
{
    vector<int> charscount=count(chars);
    vector<string> wordres={};
    int result=0;
    for(auto word : words)
    {
        vector<int> wordcount=count(word);
        if(contains(charscount,wordcount))
        {
            result+=word.length();
            wordres.push_back(word);
        }
    }
    return result;
}
int main()
{
    vector<string> words={"cat","bt","hat","tree"};
    string test="atach";
    int res=countCharacters(words,test);
    cout<<"result is : "<<res<<endl;
    cout<<"the "<<res<<" word is :"<<endl;
    cout<<endl;
    return 0;
}