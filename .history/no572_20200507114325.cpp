/*
* @Author: your name
* @Date: 2020-05-07 11:26:51
* @LastEditTime: 2020-05-07 11:35:02
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

bool isSameTree(TreeNode *s, TreeNode *t)
{
    // 同时为空 说明树一起到底，两树相同
    if (s == nullptr && t == nullptr)
    {
        return true;
    }
    return s && t && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(TreeNode *s, TreeNode *t)
{
    if (s == nullptr && t == nullptr)
    {
        return true;
    }
    if (s == nullptr && t != nullptr)
    {
        return false;
    }
    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}

/*
两个树都不为空，所以没有非空判断，因为t肯定不为空
而且题目说明了 t是子树，s是母树。少了很多麻烦

然后： s要么等于t，s的左子树等于t；s的右子树等于t。
这三种情况返回true 就是把LeetCode100的的解答再用了下

*/
bool isSameTreeV2(TreeNode *s, TreeNode *t)
{
    // 同时为空 说明树一起到底，两树相同
    if (s == nullptr && t == nullptr)
    {
        return true;
    }
    // 如果上面没有返回值，说明必有一个没有为空（有可能两个都不为空）
    if (s == nullptr || t == nullptr)
    {
        return false;
    }
    // 如果判断到了这一步，说明两个都不为空
    // 先序遍历 自己--左 -- 右
    if (s->val != t->val)
    {
        return false;
    }
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}
bool isSubtreeV2(TreeNode *s, TreeNode *t)
{
    // 我s都遍历完了。你居然还没匹配上。那就返回false
    if (s == nullptr)
    {
        return false;
    }
    // 短路运算符，有一个为真，返回真
    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}
int main()
{

    return 0;
}