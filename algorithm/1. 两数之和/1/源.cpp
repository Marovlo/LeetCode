#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> answer;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for (auto i = temp.begin(), j = temp.end() - 1; i != j;)
        {
            int now_sum = *i + *j;
            if (now_sum == target)
            {
                int flag = 0;
                for (auto f = nums.begin(); f != nums.end(); f++)
                {
                    if (*f == *i)
                    {
                        answer.push_back(distance(nums.begin(), f));
                        flag++;
                    }
                    else if (*f == *j)
                    {
                        answer.push_back(distance(nums.begin(), f));
                        flag++;
                    }
                    if (flag == 2)return answer;
                }
                return answer;
            }
            else if (now_sum > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return answer;
    };
};
int main(void)
{
    Solution a;
    vector<int>b;
    b.push_back(3);
    b.push_back(2);
    b.push_back(4);
    vector<int> answer = a.twoSum(b, 7);
    cout << answer[0] << answer[1];
    return 0;
}
