/*
 * @Author: your name
 * @Date: 2020-03-17 11:29:17
 * @LastEditTime: 2020-03-17 11:31:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\mytest1.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
using namespace std;

void tests1(string &s)
{
    s+="a";
    cout<<s<<endl;
}

void tests2(string s)
{
    s+="b";
    cout<<s<<endl;
}

int main()
{
    string test="s";
    tests1(test);
    tests2(test);
    cout<<test<<endl;
    return 0;
}