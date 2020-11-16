/*
 * @Author: your name
 * @Date: 2020-05-01 10:33:27
 * @LastEditTime: 2020-05-01 12:31:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no21.cpp


将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

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

ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
{
    ListNode* res = new ListNode(0);
    ListNode* p = res;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val < l2->val)
        {
            p->next=l1;
            l1=l1->next;
        }
        else
        {
            p->next=l2;
            l2=l2->next;
        }
        p=p->next;
    }
    // if l1==null  p->next=l2;
    // if l1!=null  p->next=l1;
    p->next=l1==NULL ? l2:l1;
    return res->next;
}

ListNode* mergeTwoListRecursion(ListNode* l1, ListNode* l2)
{
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    if(l1->val < l2->val)
    {
        l1->next=mergeTwoListRecursion(l1->next,l2);
        return l1;
    }
    l2->next=mergeTwoListRecursion(l1,l2->next);
    return l2;
}

int main()
{
   
    return 0;
}