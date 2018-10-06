class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{

		//检查行列
		for (int i = 0; i < 9; i++)
		{
			vector<bool> check_array_col(10, true); //每列一个check_array
			vector<bool> check_array_row(10, true);//每行一个check_array
			for (int j = 0; j < 9; j++)
			{
				//行
				if (board[i][j] != '.')
				{
					int index = board[i][j] - '0';
					if (check_array_col[index] == false)
						return false;
					else
						check_array_col[index] = false;
				}
				//列
				if (board[j][i] != '.')
				{
					int index = board[j][i] - '0';
					if (check_array_row[index] == false)
						return false;
					else
						check_array_row[index] = false;
				}

			}

		}
		//检查小方格
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				vector<bool> check_array(10, true);
				for (int r = 0; r < 3; r++)
				{
					for (int c = 0; c < 3; c++)
					{
						if (board[i * 3 + r][j * 3 + c] != '.')
						{
							int index = board[i * 3 + r][j * 3 + c] - '0';
							if (check_array[index] == false)
								return false;
							else
								check_array[index] = false;
						}
					}
				}
			}
		return true;
	}
};