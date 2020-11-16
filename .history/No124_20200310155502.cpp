/*
* @Author: your name
* @Date: 2020-03-10 15:53:20
 * @LastEditTime: 2020-03-10 15:55:02
 * @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecode\No124.cpp
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int ans = -10000;

int getMax(TreeNode *tn)
{
    if (tn == NULL)
    {
        return 0;
    }
    //left
    int left = max(0, getMax(tn->left));
    //right
    int right = max(0, getMax(tn->right));
    //
    int price = tn->val + left + right;
    ans = max(price, ans);

    return tn->val + max(left, right);
}

int maxPathSum(TreeNode *root)
{
    getMax(root);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    int answer=maxPathSum(root);
    return 0;
}