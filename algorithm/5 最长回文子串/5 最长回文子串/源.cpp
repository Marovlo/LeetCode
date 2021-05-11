#include<iostream>
#include<Windows.h>
#include<time.h>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
  /*
  string longestPalindrome(string s) {
    if (s.length() == 2)
    {
      if (s[0] == s[1])return s;
    }
    else if (s.length() == 1)
    {
      return s;
    }
    int max_len = 1, begin = 0, end = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
      for (int j = i+2; j < len; j++)
      {
        string sub = s.substr(i, j - i+1);
        int sub_len = sub.length();
        int flag = 1;
        for (int p = 0, q = sub_len - 1; q - p >0; q--, p++)
        {
          if (sub[q] != sub[p])
          {
            flag = 0;
            break;
          }
        }
        if (flag)
        {
          if (sub_len > max_len)
          {
            max_len = sub_len;
            begin = i;
          }
        }
      }
    }
    return s.substr(begin, max_len);
  }
  //*/
  ///*
  string longestPalindrome(string s)
  {
    if (s.length() == 2)
    {
      if (s[0] == s[1])return s;
    }
    else if (s.length() == 1)
    {
      return s;
    }
    string revrs=s;
    reverse(s.begin(), s.end());
    int len = s.length();
    int** matrix;
    matrix = (int**)malloc(sizeof(int*) * (len+1));
    for (int i = 0; i <= len; i++)
    {
      matrix[i] = (int*)malloc(sizeof(int) * (len + 1));
      memset(matrix[i], 0, sizeof(int) * (len + 1));
    }
    for (int i = 0; i < len; i++)
    {
      for (int j = 0;j < len; j++)
      {
        if (s[i] == revrs[j])
        {
          matrix[i+1][j+1] = matrix[i][j] + 1;
        }
      }
    }
    int max_len = 0, start = 0,end=0;
    for (int i = 1; i <= len; i++)
    {
      for (int j = 1; j <= len; j++)
      {
        printf("%d ", matrix[i][j]);
        if (matrix[i][j] > max_len)
        {
          max_len = matrix[i][j];
          start = i - max_len;
        }
      }
      printf("\n");
    }
    return s.substr(start, max_len);
  }
  //*/
};

int main(void)
{
  Solution ss;
  string str = "aacabkacaa";
  clock_t start = clock(), end = 0;
  cout << ss.longestPalindrome(str) << endl;
  end = clock();
  cout << end - start;
  return 0;
}