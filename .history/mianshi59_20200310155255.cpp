/*
 * @Author: enki_lee
 * @Date: 2020-03-07 14:37:04
 * @LastEditTime: 2020-03-07 14:39:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecodee:\Data Structures & algorithms Using C++\leecode\mianshi59.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <queue>
using namespace std;

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while(!d.empty()&&d.back()<value)
        {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int temp=q.front();
        if(temp==d.front())
            d.pop_front();
        q.pop();
        return temp;
    }
    queue<int> q;
    deque<int> d;
};

int main()
{
   
    return 0;
}