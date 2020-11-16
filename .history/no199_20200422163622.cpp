/*
 * @Author: your name
 * @Date: 2020-04-22 16:14:24
 * @LastEditTime: 2020-04-22 16:36:22
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
        if (node != NULL) {
            	// 维护二叉树的最大深度
                max_depth = max(max_depth, depth);

                // 由于每一层最后一个访问到的节点才是我们要的答案，因此不断更新对应深度的信息即可
                rightmostValueAtDepth[depth] =  node->val;

                nodeQueue.push(node->left);
                nodeQueue.push(node->right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);
            }
    }
    vector<int> rightView;
        for (int depth = 0; depth <= max_depth; ++depth) {
            rightView.push_back(rightmostValueAtDepth[depth]);
        }

        return rightView;
}



// DFS
vector<int> rightSideViewWithDFS(TreeNode* root)
{

} 

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=NULL;
    root->left->right=new TreeNode(5);
    root->right->left=NULL;
    root->right->right=new TreeNode(4);
    vector<int> ans = rightSideView(root);
    for(auto a in ans)
    {
        cout<<a<<endl;
    }
    return 0;
}