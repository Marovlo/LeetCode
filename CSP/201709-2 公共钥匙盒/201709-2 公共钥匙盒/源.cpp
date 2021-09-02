#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct pos
{
	bool has_key = true;
	int key_no;
}pos;

typedef struct thing
{
	enum class operation
	{
		get,
		put,
	};
	operation op;
	int key_no;
	thing(operation op, int key_no):op(op), key_no(key_no) {};
}thing;

typedef struct teacher
{
	int key_no,start,chang;
}teacher;

struct cmp
{
	bool operator()(const thing& a, const thing& b)
	{
		if (a.op == thing::put && b.op == thing::get)
		{
			return false;//put要放前面
		}
		else if (a.op == thing::get && b.op == thing::put)
		{
			return true;//get放后面
		}
		else
		{
			return a.key_no > b.key_no;//以a,b的顺序进入排序，若return false，则a在前b在后。即flase表示a,b顺序不变
		}
	}
};

typedef priority_queue<thing, vector<thing>, cmp> s_queue;


int find_key_index(pos* key_case, int key_no,int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (key_case[i].has_key && key_case[i].key_no == key_no)
		{
			return i;
		}
	}
}

int find_empty_index(pos* key_case, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (key_case[i].has_key == false)
		{
			return i;
		}
	}
}

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	pos* key_case = new pos[n];
	for (int i = 0; i < n; ++i)//初始化钥匙盒
	{
		key_case[i].key_no = i + 1;
	}
	teacher* ts = new teacher[k];
	for (int i = 0; i < k; ++i)
	{
		cin >> ts[i].key_no >> ts[i].start >> ts[i].chang;
	}
	vector<s_queue> op_table;
	op_table.resize(10000 + 100 + 1);
	for (int i = 0; i < k; ++i)
	{
		op_table[ts[i].start].push(thing(thing::get, ts[i].key_no));
		op_table[ts[i].start + ts[i].chang].push(thing(thing::put, ts[i].key_no));
	}
	for (int i = 0; i < op_table.size(); ++i)
	{
		while (op_table[i].size() != 0)
		{
			thing now = op_table[i].top();
			op_table[i].pop();
			if (now.op == thing::get)
			{
				key_case[find_key_index(key_case, now.key_no, n)].has_key = false;
			}
			else if (now.op == thing::put)
			{
				int index = find_empty_index(key_case, n);
				key_case[index].has_key = true;
				key_case[index].key_no = now.key_no;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << key_case[i].key_no << " ";
	}
	return 0;
}
