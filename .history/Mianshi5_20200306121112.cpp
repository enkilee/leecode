#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector<vector<int>> findContinuousSequence(int target)
{
    vector<vector<int>> result;
    vector<int> section;
    int i,j,sum = 0;
    int half=(target-1)/2;
    for(i=1;i<=half;i++)
    {
        for(j=i;;j++)
        {
            sum+=j;
            if(sum==target)
            {
                section.clear();
                for(int k=i;k<j;k++)
                {
                    section.emplace_back(k);
                }    
                result.emplace_back(section);
                sum=0;
                break;
            }
            else if(sum>target)
            {
                sum=0;
                break;
            }
        }
    }
    return result;
}

int main()
{
    int tar=9;
    vector<vector<int>> res= findContinuousSequence(tar);
    for(auto one:res)
    {
        for(auto two:one)
        {
            cout<<two<<' ';
        }
    }
    return 0;
}