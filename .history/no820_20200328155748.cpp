/*
 * @Author: your name
 * @Date: 2020-03-28 11:23:57
 * @LastEditTime: 2020-03-28 11:59:13
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
#include <unordered_map>

using namespace std;

class TrieNode
{
    TrieNode* children[26];
public:
    int count;
    TrieNode()
    {
        for(int i=0;i<26;++i)
        {
            children[i]=NULL;
        }
        count=0;
    }
    TrieNode* get(char c)
    {
        if(children[c-'a']==NULL)
        {
            children[c-'a']=new TrieNode();
            count++;
        }
        return children[c-'a'];
    }

}

int minimumLengthEncodingTrieNode(vector<string>& words) {
    TrieNode* trie = new TrieNode();
    unordered_map<TrieNode*,int> nodes;

    for(int i=0;i<words.size();++i)
    {
        string word = words[i];
        TrieNode* cur = trie;
        for(int j=word.length()-1;j>=0;--j)
        {
            cur=cur->get(word[j]);
        }
        nodes[cur]=i;
    }
    int ans = 0;
        for (auto& [node, idx] : nodes) {
            if (node->count == 0) {
                ans += words[idx].length() + 1;
            }
        }
        return ans;
}

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