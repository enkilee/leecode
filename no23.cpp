/*
* @Author: your name
* @Date: 2020-05-01 10:49:42
 * @LastEditTime: 2020-05-03 11:04:34
 * @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \leecode\no23.cpp
* 

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int len = lists.size();
    ListNode *res = new ListNode(0);
    ListNode *p = res;
    while (true)
    {
        ListNode *minNode = NULL;
        int minPointer = -1;
        for (int i = 0; i < len; i++)
        {
            if (lists[i] == NULL)
            {
                continue;
            }
            if (minNode == NULL || lists[i]->val < minNode->val)
            {
                minNode = lists[i];
                minPointer = i;
            }
        }
        if (minPointer == -1)
        {
            break;
        }
        p->next = minNode;
        p = p->next;
        lists[minPointer] = lists[minPointer]->next;
    }
    return res->next;
}

ListNode *mergeTwoListRecursion(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoListRecursion(l1->next, l2);
        return l1;
    }
    l2->next = mergeTwoListRecursion(l1, l2->next);
    return l2;
}
ListNode* mergeKLists(vector<ListNode*> &lists)
{
    ListNode *res = NULL;
    for (ListNode *list : lists)
    {
        res = mergeTwoListRecursion(res, list);
    }
    return res;
}
//优化 --迭代
ListNode* mergeKListsYouhua(vector<ListNode*> & lists)
{
    if(lists.size()==0)
    {
        return NULL;
    }
    int k=lists.size();
    while(k>1)
    {
        int idx=0;
        for(int i=0;i<k;i+=2)
        {
            if(i==k-1)
            {
                lists[idx++]=lists[i];
            }
            else
            {
                lists[idx++]=mergeTwoListRecursion(lists[i],lists[i+1]);
            }
        }
        k=idx;
    }
    return lists[0];
}
//优化 --- 递归
ListNode* merge(vector<ListNode*> & lists, int lo ,int hi)
{
    if(lo==hi)
    {
        return lists[lo];
    }
    int mid= lo+(hi-lo)/2;
    ListNode* l1= merge(lists,lo,mid);
    ListNode* l2= merge(lists,mid+1,hi);
    return mergeTwoListRecursion(l1,l2);
}
ListNode* mergeKListsYouhua2(vector<ListNode*> & lists)
{
    if(lists.size()==0)
    {
        return NULL;
    }
    return merge(lists,0,lists.size()-1);
}


int main()
{

    return 0;
}