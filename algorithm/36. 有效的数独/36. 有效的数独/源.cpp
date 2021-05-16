#include<vector>
#include<iostream>
#include<unordered_map>
#include<bitset>
using namespace std;

class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
      unordered_map<char, bitset<1>> row[9],col[9],block[9];
      int now_block_row = 0, now_block_candi = 0;
      char key=' ';
      for (int i = 0; i < 9; ++i)
      {
         now_block_row = (i / 3) * 3;
         for (int j = 0; j < 9; ++j)
         {
            key = board[i][j];
            if (key == '.')continue;
            now_block_candi = now_block_row + j / 3;
            if (row[i].find(key) != row[i].end())return false;
            else row[i][key] = 1;
            if (col[j].find(key) != col[j].end())return false;
            else col[j][key] = 1;
            if (block[now_block_candi].find(key) != block[now_block_candi].end())return false;
            else block[now_block_candi][key] = 1;
         }
      }
      return true;
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
   cout << s.isValidSudoku(board);
   return 0;
}