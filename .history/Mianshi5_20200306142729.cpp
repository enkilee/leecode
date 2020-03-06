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
                for(int k=i;k<=j;k++)
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
vector<vector<int>> findContinuousSequence1(int target) {
            vector<vector<int>> result;
            vector<int> section;
            int left=0;
            int right=0;
            int sum=0;
            for(left=1,right=2;left<right;)
            {
                sum=(1+right)*(right-left+1)/2;
                if(sum==target)
                {
                    for(int i=left;i<=right;i++)
                    {
                        section.emplace_back(i);
                        result.emplace_back(section);
                        left++;
                    }
                }
                else if(sum<target)
                {
                    right++;
                }
                else
                {
                    left++;
                }
            }
            return result;
    }
int main()
{
    int tar=9;
    vector<vector<int>> res= findContinuousSequence1(tar);
    for(auto one:res)
    {
        for(auto two:one)
        {
            cout<<two<<' ';
        }
        cout<<endl;
    }
    return 0;
}