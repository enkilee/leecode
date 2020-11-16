/*
 * @Author: your name
 * @Date: 2020-05-05 10:55:28
 * @LastEditTime: 2020-05-05 11:14:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no98.cpp
 * 

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。


 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

long pre = LONG_MIN;

bool isValidBST(TreeNode* root) 
{
    if(root==NULL)
    {
        return true;
    }
    //访问左子树
    if(!isValidBST(root->left))
    {
        return false;
    }
    //访问当前节点，
    //如果当前节点小于等于中序遍历的前一个节点，
    //说明不满足BST，返回 false；
    //否则继续遍历。
    if(root->val<=pre)
    {
        return false;
    }
    pre=root->val;
    //访问右子树
    return isValidBST(root->right);
}


//用递归



int main()
{
    TreeNode* tn=new TreeNode(2);
    tn->left=new TreeNode(1);
    tn->right=new TreeNode(3);
    bool res=isValidBST(tn);
    return 0;
}