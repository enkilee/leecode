/*
 * @Author: your name
 * @Date: 2020-04-14 20:25:44
 * @LastEditTime: 2020-04-14 20:53:46
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

int main()
{
    
    return 0;
}