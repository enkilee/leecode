#include <iostream>
#include <vector>

using namespace std;

    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> result(num_people,0);
        int index=0; //数量从0开始
        while(candies>0)
        {
            //这个i%num_people就很棒，随着i的增长，i对num_people进行取余数
            //返回的数会一直是相应小朋友的正确下标
            //用+=进行累加每一轮的新发的糖果
            //min的作用是，如果有一天糖不够了，就把那些最后剩余的糖给最后那个孩子
            result[i%num_people]+=min(candies,i+1);
            candies-=min(candies,i+1);
            ++i;
        }
        return result;
    }


int main()
{
   
    return 0;
}



