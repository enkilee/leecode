/*
 * @Author: your name
 * @Date: 2020-03-28 16:05:30
 * @LastEditTime: 2020-03-28 17:21:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no208.cpp
 * Trie Tree
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
        for(int i=0;i<26;i++)
        {
            next[i]=nullptr;
        }
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
};


int main()
{
    TrieNode *obj=new TrieNode();
    obj->insert("apple");
    obj->search("apple");
    obj->search("app");
    obj->startWith("app");
    obj->insert("app");
    obj->insert("app");
    return 0;
}
