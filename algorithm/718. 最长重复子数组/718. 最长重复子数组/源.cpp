#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<numeric>
#include<math.h>
#include<algorithm>
using namespace std;

class Solution {
public:
   int findLength(vector<int>& A, vector<int>& B) {
      return A.size() <= B.size() ? helper(A, B) : helper(B, A);
   }
   //���ڻ������ص����̿��Է�Ϊ�������̣�
   //1�������Ӵ����룬��ʼ�ص��Ĺ���
   //2���������Ӵ���ȫ�ص����м����
   //3��������Ӵ���ʼ�뿪���ص�������٣��뿪����
   int helper(vector<int>& A, vector<int>& B) {
      int na = A.size();
      int nb = B.size();
      int ret = 0;
      //����ʱ��Ĵ���
      for (int len = 1; len <= na; len++) {
         int tmplen = maxlen(A, 0, B, nb - len, len);
         ret = max(ret, tmplen);
      }
      //�м���̵Ĵ���
      for (int indexb = nb; indexb - na >= 0; indexb--) {
         int tmplen = maxlen(A, 0, B, indexb - na, na);
         ret = max(ret, tmplen);
      }
      //��ȥʱ�Ĵ���
      for (int len = na; len > 0; len--) {
         int tmplen = maxlen(A, na - len, B, 0, len);
         ret = max(ret, tmplen);
      }
      return ret;
   }
   int maxlen(vector<int>& A, int indexa, vector<int>& B, int indexb, int len) {
      int ret = 0;
      int countnum = 0;
      for (int i = 0; i < len; i++) {
         if (A[indexa + i] == B[indexb + i]) {
            countnum++;
         }
         else if (countnum > 0) {
            ret = max(ret, countnum);
            countnum = 0;
         }
      }
      return max(ret, countnum);
   }
};

int main(void)
{
   Solution s;
   vector<int> nums1 = { 1,2,3,2,1 };
   vector<int> nums2 = { 3,2,1,4,7 };
   cout << s.findLength(nums1, nums2);
   return 0;
}