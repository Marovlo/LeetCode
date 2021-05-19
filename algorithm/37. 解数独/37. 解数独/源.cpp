#include<iostream>
#include<vector>
#include<bitset>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
   void solveSudoku(vector<vector<char>>& board) 
   {
      int solved = 0;
      for (int i = 0; i < 9; ++i)
         for (int j = 0; j < 9; ++j)
            if (board[i][j] != '.')
               ++solved;
      dfs(board, solved);
   }

   bool dfs(vector<vector<char>>& board,int solved)
   {
      if (solved == 81)return true;
      vector<int> next_av_pos = get_next_empty(board);
      vector<int> av_nums = get_avai_num(board, next_av_pos);
      int av_size = av_nums.size();
      if (av_size == 0)return false;      
      for (int i = 0; i < av_size; ++i)
      {
         board[next_av_pos[0]][next_av_pos[1]] = av_nums[i] + 48;
         if (!dfs(board, ++solved))//若不行 则撤销
         {
            board[next_av_pos[0]][next_av_pos[1]] = '.';
            solved -= 1;
         }
         else return true;
      }
      return false;
   }

   vector<int> get_next_empty(const vector<vector<char>>& board)
   {
      for (int i = 0; i < 9; ++i)
      {
         for (int j = 0; j < 9; ++j)
         {
            if (board[i][j] == '.')return { i,j };
         }
      }
      return { -1,-1 };
   }

   vector<int> get_avai_num(const vector<vector<char>>&board,vector<int>pos)
   {
      unordered_map<int, bool> sum_av_num;
      vector<int> ans;
      int row_no = pos[0], col_no = pos[1];
      for (int i = 0; i < 9; ++i)
      {
         if (board[row_no][i] != '.')sum_av_num[board[row_no][i] - 48] = true;
         if (board[i][col_no] != '.')sum_av_num[board[i][col_no] - 48] = true;
      }
      int row_start = row_no / 3 * 3, row_end = row_start + 3;
      int col_start = col_no / 3 * 3, col_end = col_start + 3;
      for (int i = row_start; i < row_end; ++i)
      {
         for (int j = col_start; j < col_end; ++j)
         {
            if (board[i][j] != '.')sum_av_num[board[i][j] - 48] = true;
         }
      }
      for (int i = 1; i < 10; ++i)
      {
         if (sum_av_num.find(i) == sum_av_num.end())
         {
            ans.push_back(i);
         }
      }
      return ans;
   }
};


int main(void)
{
   vector<vector<char>> board = { \
   {'5', '3', '.', '.', '7', '.', '.', '.', '.'},\
   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},\
   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},\
   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},\
   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},\
   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},\
   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},\
   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},\
   {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
   Solution s;
   s.solveSudoku(board);
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; ++j)
      {
         cout.put(board[i][j]);
         cout << " ";
      }
      cout << "\n";
   }
   return 0;
}