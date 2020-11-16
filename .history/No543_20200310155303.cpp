/*
 * @Author: your name
 * @Date: 2020-03-10 15:53:01
 * @LastEditTime: 2020-03-10 15:53:02
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leecode\No543.cpp
 */
/*
* @Author: your name
* @Date: 2020-03-10 14:49:07
 * @LastEditTime: 2020-03-10 14:57:31
 * @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecodee:\Data Structures & algorithms Using C++\leecode\No543.cpp
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
int ans;
int depth(TreeNode *rt)
{
    if (rt == NULL)
        return 0;              // 访问到空节点了，返回0
    int L = depth(rt->left);   // 左儿子为根的子树的深度
    int R = depth(rt->right);  // 右儿子为根的子树的深度
    ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
    return max(L, R) + 1;      // 返回该节点为根的子树的深度
}
int diameterOfBinaryTree(TreeNode *root)
{
    ans = 1;
    depth(root);
    return ans - 1;
}
int main()
{
    TreeNode *root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right=new TreeNode(3);

    int res = diameterOfBinaryTree(root);
    return 0;
}