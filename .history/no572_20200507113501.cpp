/*
* @Author: your name
* @Date: 2020-05-07 11:26:51
* @LastEditTime: 2020-05-07 11:27:29
* @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecode\no572.cpp


给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

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

bool isSameTree(TreeNode *s,TreeNode *t)
{
    if(s==nullptr&&t==nullptr)
    {
        return true;
    }
    return s&&t
            && isSameTree(s->left,t->left)
            && isSameTree(s->right,t->right);
}

bool isSubtree(TreeNode *s, TreeNode *t)
{
    if(s==nullptr&&t==nullptr)
    {
        return true;
    }
    if(s==nullptr&&t!=nullptr)
    {
        return false;
    }
    return isSameTree(s,t)
            ||isSubtree(s->left,t)
            ||isSubtree(s->right,t);
}
int main()
{

    return 0;
}