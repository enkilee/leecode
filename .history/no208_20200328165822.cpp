/*
 * @Author: your name
 * @Date: 2020-03-28 16:05:30
 * @LastEditTime: 2020-03-28 16:58:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no208.cpp
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class TrieNode
{
private:
    bool isEnd;
    TrieNode* next[26];
public:
    TrieNode()
    {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    void insert(string word)
    {
        TrieNode* node =this;
        for(char c:word)
        {
            if(node->next[c-'a']==NULL)
            {
                node->next[c-'a']=new TrieNode();
            }
            node=node->next[c-'a'];
        }
        node->isEnd=true;
    }

    bool search(string word)
    {
        TrieNode * node = this;
        for(char c:word)
        {
            node=node->next[c-'a'];
            if(node==NULL)
            {
                return false;
            }
        }
        return node->isEnd;
    }
    bool startWith(string prefix)
    {
        TrieNode * node = this;
        for(char c:prefix)
        {
            node=node->next[c-'a'];
            if(node==NULL)
            {
                return false;
            }
        }
        return true;
    }
}


int main()
{
   
    return 0;
}
