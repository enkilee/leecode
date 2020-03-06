/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
        if(!matrix.size() || !matrix[0].size())
        return {};
        vector<int> res;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<bool>> st(n,vector<bool>(m,0));
        int dx[]={0,1,1,-1};
        int dy[]={1,-1,0,1};

        int x=0,y=0,d=0;
        for(int i=1;i<=m*n;i++)
        {
            res.push_back(matrix[x][y]);
            st[x][y]=true;

            if(i==n*m)
                break;
            //利用(a,b)找到下一个可以走的点
            int a=x+dx[d],b=y+dy[d];
            while(a<0 ||a>=n ||b<0||b>=m||st[a][b]==true)
            {
                d=(d+1)%4;
                a=x+dx[d],b=y+dy[d];
            }
            //让(x,y)变成下一个可走的点，然后进入下一个循环
            x=x+dx[d];
            y=y+dy[d];
            if(d==0||d==2)
            {
                d=(d+1)%4;
            }
        }
        return res;


    }
};
// @lc code=end

