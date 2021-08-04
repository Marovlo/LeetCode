#include<iostream>
using namespace std;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int red, yellow, green, n;
	//int sum = 0;
	long long sum = 0;
	cin >> red >> yellow >> green >> n;
	int aturn = red + yellow + green;
	for (int i = 0; i < n; ++i)
	{
		int k, t;
		cin >> k >> t;
		if (k == 0)sum += t;
		else
		{
			if (k == 1)//出发时为红灯
			{
				if (sum < t)
				{
					sum += t - sum;//剩下的等待时间，然后为绿灯，可以前进
				}
				else 
				{
					int pass = (sum - t) % aturn;
					if (pass <= green)//红灯下一个为绿灯，且当前为绿灯
					{
						sum;//直接通过
					}
					else if(pass<=green+yellow)//当前为黄灯
					{
						sum += green + yellow - pass + red;
					}
					else //当前为红灯
					{
						sum += aturn - pass;
					}
				}
			}
			else if (k == 2)//出发为黄灯
			{
				if (sum < t)
				{
					sum += t - sum + red;//等待剩下的黄灯，然后等待全部红灯
				}
				else
				{
					int pass = (sum - t) % aturn;
					if (pass <= red)
					{
						sum += red - pass;//当前为红灯，等待剩下的红灯
					}
					else if (pass <= red + green)
					{
						sum;//当前为绿灯直接通过
					}
					else
					{
						sum += aturn - pass + red;//当前为黄灯，等完黄灯之后还要等一个红灯才能通过
					}
				}
			}
			else if (k == 3)//出发为绿灯
			{
				if(sum<t)//当前还是绿灯
				{
					sum;//直接通过
				}
				else
				{
					int pass = (sum - t) % aturn;
					if (pass <= yellow)
					{
						sum += yellow - pass + red;//到达为黄灯，等待剩下的黄灯，然后等待全部红灯
					}
					else if (pass < yellow + red)
					{
						sum += yellow + red - pass;//到达时为红灯，等待剩下的红灯
					}
					else
					{
						sum;//到达时为绿灯，直接通过
					}
				}
			}
		}
	}
	cout << sum;
}