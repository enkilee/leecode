#include <iostream>
#include <vector>


using namespace std;

int findduplicate(vector<int>& nums)
{
    int slow=nums[0];
    int fast=nums[0];
    do
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while(slow!=fast);
    
    int ptr1=nums[0];
    int ptr2=slow;
    while(ptr1!=ptr2)
    {
        ptr1=nums[ptr1];
        ptr2=nums[ptr2];
    }
    return ptr1;
}

int main()
{
    vector<int> num={1,2,3,5,4,6,3,3};
    int res = findduplicate(num);
    cout<<"res: "<<res<<endl;

    return 0;
}