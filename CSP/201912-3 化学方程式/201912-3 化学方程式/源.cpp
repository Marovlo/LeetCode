#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int get_digit(string eu, int& start)
{
	int t = start;
	int len = eu.length();
	while (t != len && isdigit(eu[t]))t++;
	int num = stoi(string(eu.begin() + start, eu.begin() + t));
	start = t;
	return num;
}

string get_a_element(string eu, int& start)
{
	int len = eu.length();
	string ans;
	ans += eu[start];
	if (start != len - 1 && islower(eu[start + 1]))
	{
		ans += eu[start + 1];
		++start;
	}
	++start;
	return ans;
}

void append(unordered_map<string, int>& res, string name, int num)
{
	if (res.find(name) != res.end())
		res[name] += num;
	else
		res[name] = num;
}


unordered_map<string, int> deal_quoat(string eu, int& start)
{
	int len = eu.length();
	unordered_map<string, int>res;
	int i;
	for (i = start + 1; eu[i] != ')'; ++i)
	{
		string now_ele;
		int num = 1;
		if (isupper(eu[i]))
		{
			now_ele = get_a_element(eu, i);
			if (isdigit(eu[i]))
			{
				num = get_digit(eu, i);
			}
			append(res, now_ele, num);
		}
	}
	start += 1;
	return res;
}

void get_element(unordered_map<string,int> &res,string eu)
{
	int len = eu.length();
	for (int i = 0; i < len; ++i)
	{
		if (eu[i] == '+')continue;
		else if (eu[i] == '(')
		{
			unordered_map<string, int> temp = deal_quoat(eu, i);
			int times = 1;
			if (isdigit(eu[i]))
			{
				times = get_digit(eu, i);
			}
			for (auto j = temp.begin(); j != temp.end(); ++j)
			{
				append(res, (*j).first, (*j).second * times);
			}
		}
		else if (isdigit(eu[i]))
		{
			int times = get_digit(eu, i);

		}
	}
}

bool compare_map(unordered_map<string, int> a, unordered_map<string, int>b)
{
	if (a.size() != b.size())return false;
	else
	{
		for (auto i = a.begin(); i != a.end(); ++i)
		{
			if (b.find((*i).first) == b.end())return false;
			else
			{
				if (b[(*i).first] != (*i).second)return false;
			}
		}
	}
	return true;
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		unordered_map<string, int> left, right;
		string equation;
		cin >> equation;
		while (equation[i]!='=')
		{
			++i;
		}
		get_element(left, string(equation.begin(), equation.begin() + i));
		get_element(right, string(equation.begin() + i, equation.end()));
		cout << (compare_map(left, right) ? 'Y' : 'N') << endl;
	}
}
