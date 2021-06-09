#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  /*
  暴力算法嗷
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      for (int i : nums2)
      {
          nums1.push_back(i);
      }
      sort(nums1.begin(), nums1.end());
      int size = nums1.size();
      return size % 2 == 0 ? static_cast<double>(nums1[size / 2 - 1] + nums1[size / 2]) / 2 : nums1[size / 2];
  }
  //*/
  /*还是挺暴力的
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> all;
    int n1size = nums1.size();
    int n2size = nums2.size();
    for (int i = 0, j = 0; i < n1size || j < n2size;)
    {
      if (i == n1size)
      {
        while (j < n2size)
        {
          all.push_back(nums2[j++]);
        }
        break;
      }
      else if (j == n2size)
      {
        while (i < n1size)
        {
          all.push_back(nums1[i++]);
        }
        break;
      }
      int smaller = nums1[i] < nums2[j] ? 0 : 1;
      int toPush = smaller == 0 ? nums1[i] : nums2[j];
      all.push_back(toPush);
      smaller == 0 ? i++ : j++;
    }
    int size = all.size();
    return size % 2 == 0 ? static_cast<double>(all[size / 2 - 1] + all[size / 2]) / 2 : all[size / 2];
  }
  //*/
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    int total = nums1.size() + nums2.size();
    int k = 0, rank = total / 2;
    int midnum1 = 0, midnum2 = 0, whochanged = 0, out = 0;
    int iflag = 0, jflag = 0;
    if (nums1.size() == 0)
    {
      int len = nums2.size();
      if (len % 2 == 0)
      {
        return ((double)nums2[len / 2] + (double)nums2[len / 2 - 1]) / 2;
      }
      else
      {
        return nums2[len / 2];
      }
    }
    else if (nums2.size() == 0)
    {
      int len = nums1.size();
      if (len % 2 == 0)
      {
        return ((double)nums1[len / 2] + (double)nums1[len / 2 - 1]) / 2;
      }
      else
      {
        return nums1[len / 2];
      }
    }
    else
    {
      for (int i = 0, j = 0; k <= rank; k++)
      {
        if (nums1[i] > nums2[j])
        {
          if (j == nums2.size() - 1)
          {
            if (jflag == 0)
            {
              out = nums2[j];
              jflag = 1;
            }
            else
            {
              out = nums1[i];
              i++;
            }
          }
          else
          {
            out = nums2[j];
            j++;
          }
        }
        else
        {
          if (i == nums1.size() - 1)
          {
            if (iflag == 0)
            {
              out = nums1[i];
              iflag = 1;
            }
            else
            {
              out = nums2[j];
              j++;
            }
          }
          else
          {
            out = nums1[i];
            i++;
          }
        }

        if (whochanged == 0)
        {
          midnum1 = out;
          whochanged = 1;
        }
        else
        {
          midnum2 = out;
          whochanged = 0;
        }
      }
      if (total % 2 == 0)
      {
        return ((double)midnum1 + (double)midnum2) / 2;
      }
      else
      {
        return midnum1 > midnum2 ? midnum1 : midnum2;
      }
    }
  }
};

int main(void)
{
  vector<int> nums1 = { 1,3 };
  vector<int> nums2 = { 2 };
  cout << Solution().findMedianSortedArrays(nums1, nums2);
  return 0;
}