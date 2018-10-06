class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //×ªÖÃ
        int len = matrix.size();
        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = i+1; j < len; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //¶Ô³Æ
        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = 0; j < len / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][len-j-1];
                matrix[i][len-j-1] = temp;
            }
        }
    }
};