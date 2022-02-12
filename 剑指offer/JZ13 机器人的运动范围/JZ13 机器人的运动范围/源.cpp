#include"resources.h"

class Solution
{
public:
    int movingCount(int threshold, int rows, int cols) {
        int res = 0;
        vector<vector<bool>> map(rows, vector<bool>(cols, false));
        dfs(threshold, rows, cols, 0, 0, res, map);
        return res;
    }

    void dfs(int threshold,int rows, int cols, int i, int j,int& res,vector<vector<bool>>& map)
    {
        if (i < 0 || i >= rows || j<0 || j>=cols|| get_threshold(i, j) > threshold)return;
        else
        {
            if (map[i][j] == false)
            {
                ++res;
                map[i][j] = true;//表示去过了，不加格子，也不可以走
                dfs(threshold, rows, cols, i + 1, j, res, map);
                dfs(threshold, rows, cols, i - 1, j, res, map);
                dfs(threshold, rows, cols, i, j + 1, res, map);
                dfs(threshold, rows, cols, i, j - 1, res, map);
            }
        }
    }

    int get_threshold(int i, int j)
    {
        int sum = 0;
        while (i != 0)
        {
            sum += i % 10;
            i /= 10;
        }
        while (j != 0)
        {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }
};


int main(void)
{
	Solution s;
    cout << s.movingCount(15, 20, 20);
    int res = 0;
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            int thre = s.get_threshold(i, j);
            if (thre <= 15)++res;
            printf("%2d ", thre);
        }
        cout << endl;
    }
    cout << res;
	return 0;
}