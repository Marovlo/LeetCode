#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum Status
{
	unallocated = 0,
	preallocated = 1,
	occupied = 2,
	timeout = 3
};

struct IP
{
	int ip_addr;
	Status status = unallocated;
	string occupier = "";
	int timeout = 0;
};

struct message
{
	int t, ip_addr, timeout;
	string from_name, to_name, message_type;
};

class DHCP_server
{
public:
	vector<IP> ips;
	int size;
	int tdef, tmax, tmin;
	string name;
	DHCP_server(int size, int tfed, int tmax, int tmin, string name);
	void deal_message(const message& m);
	void deal_DIS(const message& m);
	void deal_REQ_to_me(const message& m);
	void deal_REQ_to_other(const message& m);
};

int main(void)
{
	freopen("in.txt", "r", stdin);
	int size, tdef, tmax, tmin,n;
	string name;
	cin >> size >> tdef >> tmax >> tmin >> name >> n;
	DHCP_server server(size,tdef,tmax,tmin,name);
	for (int i = 0; i < n; ++i)
	{
		message m;
		cin >> m.t >> m.from_name >> m.to_name >> m.message_type >> m.ip_addr >> m.timeout;
		server.deal_message(m);
	}
	return 0;
}

DHCP_server::DHCP_server(int size, int tfed, int tmax, int tmin, string name):
	size(size),tdef(tdef),tmax(tmax),tmin(tmin),name(name)
{
	for (int i = 1; i <= size; ++i)
	{
		IP aip;
		aip.ip_addr = i;
	}
	return;
}

void DHCP_server::deal_message(const message& m)
{
	if (m.to_name == "*" && m.message_type == "DIS")//discover
		this->deal_DIS(m);
	else if (m.to_name == this->name && m.message_type == "REQ")
		this->deal_REQ_to_me(m);
	else if (m.to_name != this->name && m.message_type == "REQ")
		this->deal_REQ_to_other(m);
}

void DHCP_server::deal_DIS(const message& m)
{
	int choosed_ip=0;
	int accept_timeout = 0;
	for (int i = 0; i < size; ++i)
	{
		if (ips[i].occupier == m.from_name)
		{
			choosed_ip = ips[i].ip_addr;
			if (m.timeout==0)accept_timeout = m.t + tdef;
			else
			{
				int excpet_timeout=m.timeout+
			}
			break;
		}
	}
	if(choosed_ip==0)
	{
		for (int i = 0; i < size; ++i)
		{
			if (ips[i].status == unallocated)
			{
				choosed_ip = ips[i].ip_addr;
				break;
			}
		}
	}
	if (choosed_ip == 0)
	{
		for (int i = 0; i < size; ++i)
		{
			if (ips[i].status == timeout)
			{
				choosed_ip == ips[i].ip_addr;
				break;
			}
		}
	}
	else return;
	cout>>name>>" ">> m.from_name>>" ">>"OFR">>" ">>
}