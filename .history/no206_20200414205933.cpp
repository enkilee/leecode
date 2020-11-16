/*
 * @Author: your name
 * @Date: 2020-04-14 20:25:44
 * @LastEditTime: 2020-04-14 20:59:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no206.cpp
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
    ListNode(int x):val(x),next(NULL){}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* pre;
    ListNode* curr=head;
    ListNode* temp;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=pre;
        pre=curr;
        curr=temp;
    }
    return pre;
}

/*
难懂，要仔细琢磨
假设链表是[1, 2, 3, 4, 5]从最底层最后一个reverseList(5)来看
1 返回了5这个节点
2 reverseList(4)中
3 p为5
4 head.next.next = head 相当于 5 -> 4
5 现在节点情况为 4 -> 5 -> 4
6 head.next = null,切断4 -> 5 这一条，现在只有 5 -> 4
7 返回（return）p为5，5 -> 4
8 返回上一层reverseList(3)
9 处理完后返回的是4 -> 3
10 依次向上
*/
ListNode* reverseListDigui(ListNode* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    ListNode* p = reverseListDigui(head->next);
    head->next->next=head;
    head->next=NULL;
    return p;
}

// 双指针
ListNode* reverseListDouble(ListNode* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    ListNode* cur= head;
    while(head->next!=NULL)
    {
        ListNode* t= head->next->next;
        head->next->next=cur;
        cur=head->next;
        head->next=t;
    }
    return cur;
}
int main()
{
    
    return 0;
}