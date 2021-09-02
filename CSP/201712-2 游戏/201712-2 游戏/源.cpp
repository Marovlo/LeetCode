#include<iostream>
#include<vector>
using namespace std;

typedef struct node
{
	int no;
	node* next;
}node;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	node* head = new node;
	head->no = 1;
	node* cur = head;
	for (int i = 2; i <= n; ++i)
	{
		node* temp = new node;
		temp->no = i;
		cur->next = temp;
		cur = temp;
	}
	node* pre = cur;//最后一个
	cur->next = head;//回环
	cur = head;
	for (int i = 1; cur->next != cur; ++i)
	{
		if (i % k == 0 || i % 10 == k)
		{
			pre->next = cur->next;
			delete cur;
			cur = pre->next;
		}
		else
		{
			cur = cur->next;
			pre = pre->next;
		}
	}
	delete cur;
	cout << cur->no;
	return 0;
}