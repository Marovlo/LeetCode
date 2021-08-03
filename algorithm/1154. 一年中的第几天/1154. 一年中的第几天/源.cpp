#include<string>
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
   int dayOfYear(string date) {

      vector<int> days_no_leap = { 0, 31,28, 31, 30, 31, 30, 31,31,30,31, 30, 31 };
      vector<int> days_leap = { 0, 31,29, 31, 30, 31, 30, 31,31,30,31, 30, 31 };

      int year = stoi(date.substr(0, 4));
      int month = stoi(date.substr(5, 2));
      int day = stoi(date.substr(8, 2));

      int sum = 0;

      if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
         sum = accumulate(days_leap.begin(), days_leap.begin() + month, day);
      }
      else {
         sum = accumulate(days_no_leap.begin(), days_no_leap.begin() + month, day);
      }

      return sum;
   }
};


int main(void)
{
   Solution s;
   cout<<s.dayOfYear("2018-02-01");
   return 0;
}