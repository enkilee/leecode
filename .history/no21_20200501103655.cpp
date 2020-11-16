/*
 * @Author: your name
 * @Date: 2020-05-01 10:33:27
 * @LastEditTime: 2020-05-01 10:36:54
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
    l1==NULL ? l2:l1;
    p->next=l1;
    return res->next;
    
}

int main()
{
   
    return 0;
}