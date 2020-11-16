/*
 * @Author: your name
 * @Date: 2020-04-10 15:16:30
 * @LastEditTime: 2020-04-10 15:16:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leecode\no151.cpp
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

string reverseWords(string s) 
{
    string ans, str;
    vector<string> tmp;
    stringstream ss(s);
    while (ss >> str) tmp.push_back(str);
    for (int i = tmp.size() - 1; i >= 0; i--) ans += tmp[i] + " ";
    return ans.size() ? string(ans.begin(), ans.end() - 1) : "";
}

int main()
{
   
    return 0;
}