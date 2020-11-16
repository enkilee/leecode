/*
 * @Author: your name
 * @Date: 2020-05-01 10:49:42
 * @LastEditTime: 2020-05-01 11:07:59
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

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    int len=lists.size();
    ListNode* res = new ListNode(0);
    ListNode* p = res;
    while(true)
    {
        ListNode* minNode = NULL;
        int minPointer=-1;
        for(int i=0;i<len;i++)
        {
            if(lists[i]==NULL)
            {
                continue;
            }
            if(minNode==NULL || lists[i]->val<minNode->val)
            {
                minNode=lists[i];
                minPointer=i;
            }
        }
        if(minPointer==-1)
        {
            break;
        }
        p->next=minNode;
        p=p->next;
        lists[minPointer]=lists[minPointer]->next;
    }    
    return res->next;
}
int main()
{
   
    return 0;
}