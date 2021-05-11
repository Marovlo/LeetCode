#include<iostream>
#include<string>
#include<vector>
using namespace std;


//sunday算法，实际情况下比kmp算法稍好，算法复杂度最好O(n),最坏O(mn)
//sunday算法，首先计算出待匹配串的每一个字符在字符串中最后一次出现的下标，用待匹配字符串的长度减去该下标，
//即为遇到该字符时的向右移动的长度。未出现的字符的shift长度都为字符串长度加一
//算法流程为，每次从原字符串中取出长度为待匹配字符串长度的字串从i到i+len，比较这两个串，若相同，直接返回i
//若不同，看原字符串i+len+1的字符，即下一个字符在shift数组中的值为多少，即偏移量为多少，然后使i=i+该值
//反复执行，直到返回i或者i+len>原字符串长度时返回-1。
class Solution {
public:
   int strStr(string haystack, string needle)
   {
      int haylen = haystack.length();
      int needlen = needle.length();
      if (needlen == 0)return 0;
      vector<int> shift = get_shift(needle);
      for (int i = 0; i + needlen <= haylen;)
      {
         string now{haystack.begin()+i,haystack.begin()+i+needlen};
         if (now != needle)i += shift[haystack[i + needlen]];
         else return i;
      }
      return -1;
   }
   vector<int> get_shift(string needle)
   {
      int len = needle.length();
      vector<int>shift(256,len+1);
      for (int i = 0; i < len; ++i)
      {
         shift[needle[i]] = len - i;
      }
      return shift;
   }
};

int main(void)
{
   Solution s;
   cout << s.strStr("checkthisout", "this");
   return 0;
}


/*
class Solution {
public:
   vector<int> get_next(string str)
   {
      int len = str.length();
      vector<int> next{ 0 };
      for (int i = 1; i < len; ++i)
      {

      }
   }


   int strStr(string haystack, string needle) {
      int pos = -1;
      int len = haystack.length();
      int needle_len = needle.length();
      if (needle_len == 0)return 0;
      for (int i = 0; i < len; ++i)
      {
         int p1 = i, p2 = 0;
         while (haystack[p1++]==needle[p2++])
         {
            if (p1 >= len)return -1;
            if (p2 == needle_len)return i;
         }
      }
      return -1;
   }
};

//*/