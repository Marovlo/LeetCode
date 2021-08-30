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
	IP* ips;
	int size;
	int tdef, tmax, tmin;
	string name;
	DHCP_server(int size, int tfed, int tmax, int tmin, string name);
	void deal_message(const message& m);
	void deal_DIS(const message& m);
	void deal_REQ(const message& m);
};

int main(void)
{
	//freopen("in.txt", "r", stdin);
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

DHCP_server::DHCP_server(int size, int tdef, int tmax, int tmin, string name):
	size(size),tdef(tdef),tmax(tmax),tmin(tmin),name(name)
{
	ips = new IP[size + 1];
	for (int i = 0; i < size; ++i)
	{
		ips[i].ip_addr = i + 1;//初始化ip池
	}
	return;
}

void DHCP_server::deal_message(const message& m)
{
	//根据报文获取当前时间，更改服务器ip池中所有ip的状态
	for (int i = 0; i < size; ++i)
	{
		if (ips[i].timeout != 0 && ips[i].timeout <= m.t)
		{
			if (ips[i].status == preallocated)
			{
				ips[i].status = unallocated;
				ips[i].occupier = "";//待分配超时时清除占用者
				ips[i].timeout = 0;
			}
			else if (ips[i].status == occupied)
			{
				ips[i].status = timeout;
				ips[i].timeout = 0;//占用状态超时时不清楚占用者
			}
		}
	}
	if (m.message_type == "DIS")
	{
		if (m.to_name == "*")this->deal_DIS(m);
		else;//do noting
	}
	else if (m.message_type == "REQ")
	{
		if (m.to_name == "*");//do npthing
		else this->deal_REQ(m);
	}
	else;//do nothing
}

void DHCP_server::deal_REQ(const message& m)
{
	if (m.to_name != name)//检查接收主机是否为本机
	{
		//若不是
		for (int i = 0; i < size; ++i)
		{
			if (ips[i].occupier == m.from_name)
			{
				if (ips[i].status == preallocated)
				{
					ips[i].status = unallocated;
					ips[i].occupier = "";
					ips[i].timeout = 0;
				}
			}
		}
	}
	else
	{
		//若是
		if (m.ip_addr <= size + 1 && ips[m.ip_addr - 1].occupier == m.from_name)//检查报文中的 IP 地址是否在地址池内，且其占用者为发送主机
		{
			//yes
			ips[m.ip_addr - 1].status = occupied;
			if (m.timeout == 0) //若报文中过期时刻为 0 ，则设置过期时刻为 t+tdef
			{
				ips[m.ip_addr - 1].timeout = m.t + tdef;
			}
			else//否则根据报文中的过期时刻和收到报文的时刻计算过期时间，判断是否超过上下限：
				//若没有超过，则设置过期时刻为报文中的过期时刻；
				//否则则根据超限情况设置为允许的最早或最晚的过期时刻；
			{
				if (m.timeout <= m.t + tmin)ips[m.ip_addr - 1].timeout = m.t + tmin;
				else if (m.timeout >= m.t + tmax)ips[m.ip_addr - 1].timeout = m.t + tmax;
				else ips[m.ip_addr - 1].timeout = m.timeout;
			}
			cout << name << " " << m.from_name << " " << "ACK" << " " << ips[m.ip_addr - 1].ip_addr << " " << ips[m.ip_addr - 1].timeout << endl;
		}
		else
		{
			//no
			cout << name << " " << m.from_name << " " << "NAK" << " " << m.ip_addr << " " << 0 << endl;
		}
	}
}

void DHCP_server::deal_DIS(const message& m)
{
	int choosed_ip;
	bool choosed = false;
	for (int i = 0; i < size; ++i)
	{
		if (ips[i].occupier == m.from_name)//检查是否有占用者为发送主机的 IP 地址
		{
			choosed_ip = i;
			choosed = true;
			break;
		}
	}
	if (!choosed)//若没有，则选取最小的状态为未分配的 IP 地址；
	{
		for (int i = 0; i < size; ++i)
		{
			if (ips[i].status == unallocated)
			{
				choosed_ip = i;
				choosed = true;
				break;
			}
		}
	}
	if (!choosed)//若没有，则选取最小的状态为过期的 IP 地址；
	{
		for (int i = 0; i < size; ++i)
		{
			if (ips[i].status == timeout)
			{
				choosed_ip = i;
				choosed = true;
				break;
			}
		}
	}
	if(!choosed) return;//若ren没有，则不处理该报文，处理结束；
	ips[choosed_ip].status = preallocated;//将该 IP 地址状态设置为待分配
	ips[choosed_ip].occupier = m.from_name;//占用者设置为发送主机；
	if (m.timeout == 0) //若报文中过期时刻为 0 ，则设置过期时刻为 t+tdef
	{
		ips[choosed_ip].timeout = m.t + tdef;
	}
	else//否则根据报文中的过期时刻和收到报文的时刻计算过期时间，判断是否超过上下限：
		//若没有超过，则设置过期时刻为报文中的过期时刻；
		//否则则根据超限情况设置为允许的最早或最晚的过期时刻；
	{
		if (m.timeout <= m.t+tmin)ips[choosed_ip].timeout = m.t + tmin;
		else if (m.timeout >= m.t + tmax)ips[choosed_ip].timeout = m.t + tmax;
		else ips[choosed_ip].timeout = m.timeout;
	}
	//向发送主机发送 Offer 报文，其中，IP 地址为选定的 IP 地址，过期时刻为所设定的过期时刻。
	cout << name << " " << m.from_name << " " << "OFR" << " " << ips[choosed_ip].ip_addr << " " << ips[choosed_ip].timeout << endl;
}