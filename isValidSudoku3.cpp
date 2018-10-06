class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        //row;
        for(int i=0;i<9;++i)
        {
            
            vector<int>bucket(10,0);
            for(int j=0;j<9;++j)
            {
                if(board[i][j]>='0'&&board[i][j]<='9')
                {
                    
                    ++bucket[board[i][j]-'0'];
                    if(bucket[board[i][j]-'0']>1)
                        return false;
                }
            }
            
        }
        //col
        for(int i=0;i<9;++i)
        {
            vector<int>bucket(10,0);
            for(int j=0;j<9;++j)
            {
                if(board[j][i]>='0'&&board[j][i]<='9')
                {
                    ++bucket[board[j][i]-'0'];
                    if(bucket[board[j][i]-'0']>1)
                        return false;
                }
            }
            
        }
        //3*3
        for(int i=0;i<=6;i+=3)
        {
            for(int j=0;j<=6;j+=3)
            {
                vector<int>bucket(10,0);
                for(int m=i;m<i+3;++m)
                {
                    for(int n=j;n<j+3;++n)
                    {
                        if(board[m][n]>='0'&&board[m][n]<='9')
                        {
                            ++bucket[board[m][n]-'0'];
                            if(bucket[board[m][n]-'0']>1)
                                return false;
                        }
                    }
                }
                
            }
        }
        return true;
    }
};