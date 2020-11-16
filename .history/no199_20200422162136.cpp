/*
 * @Author: your name
 * @Date: 2020-04-22 16:14:24
 * @LastEditTime: 2020-04-22 16:21:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no199.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//BFS:

vector<int> rightSideView(TreeNode* root) 
{
    unordered_map<int,int> rightmostValueAtDepth;
    int max_depth=-1;
    
    queue<TreeNode*> nodeQueue;
    queue<int> depthQueue;
    nodeQueue.push(root);
    depthQueue.push(0);

    while(!nodeQueue.empty())
    {
        TreeNode* node =nodeQueue.front();
        nodeQueue.pop();
        int depth=depthQueue.front();
        depthQueue.pop();
    }
}
int main()
{
   
    return 0;
}