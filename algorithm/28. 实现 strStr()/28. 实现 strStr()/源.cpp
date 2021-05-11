#include<iostream>
#include<string>
#include<vector>
using namespace std;


//sunday�㷨��ʵ������±�kmp�㷨�Ժã��㷨���Ӷ����O(n),�O(mn)
//sunday�㷨�����ȼ������ƥ�䴮��ÿһ���ַ����ַ��������һ�γ��ֵ��±꣬�ô�ƥ���ַ����ĳ��ȼ�ȥ���±꣬
//��Ϊ�������ַ�ʱ�������ƶ��ĳ��ȡ�δ���ֵ��ַ���shift���ȶ�Ϊ�ַ������ȼ�һ
//�㷨����Ϊ��ÿ�δ�ԭ�ַ�����ȡ������Ϊ��ƥ���ַ������ȵ��ִ���i��i+len���Ƚ���������������ͬ��ֱ�ӷ���i
//����ͬ����ԭ�ַ���i+len+1���ַ�������һ���ַ���shift�����е�ֵΪ���٣���ƫ����Ϊ���٣�Ȼ��ʹi=i+��ֵ
//����ִ�У�ֱ������i����i+len>ԭ�ַ�������ʱ����-1��
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