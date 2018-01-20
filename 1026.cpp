#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <list>
using namespace std;
enum Tag { NonVip, Vip};
void PrintTime(int time)
{
	printf("%02d:%02d:%02d", time / 3600, time / 60 % 60, time % 60);
}
struct Player
{
	int arrivingTime;
	int playingTime;
	int servingTime=0;
	Tag tag;
	Player(int timePoint,int playingTime,Tag tag):
	arrivingTime(timePoint),playingTime(playingTime),tag(tag)
	{}
	bool operator < (const Player& rhs) const
	{
		return arrivingTime < rhs.arrivingTime;
	}
	void Print()
	{
		PrintTime(arrivingTime);
		cout << " ";
		PrintTime(servingTime);
		int waitingTime = servingTime - arrivingTime;
		if (waitingTime % 60 >=30)waitingTime += 60;
		cout << " "<<waitingTime/60<<'\n';
	}
};
struct Table
{
	Tag tag;
	int endTime;
	explicit Table(int endTime=8*3600,Tag tag=NonVip):
	tag(tag),endTime(endTime)
	{ }
	bool operator <(const Table& rhs)const
	{
		return endTime < rhs.endTime;
	}
	int servePlayerSize = 0;
};
int N;
vector<Player> players;
int totalTableSize, vipTableSize;
vector<Table> tables;
vector<reference_wrapper<Table>> vipTables;
void Prepare()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int timePoint = (hh * 60 + mm) * 60 + ss;
		int playTime, tag;
		cin >> playTime >> tag;
		if (hh >= 21)continue;
		if (playTime > 120)playTime = 120;//cut off
		players.emplace_back(timePoint, playTime*60, Tag(tag));
	}
	cin >> totalTableSize >> vipTableSize;
	for (int i = 0; i < totalTableSize; ++i)
		tables.emplace_back();
	for (int i = 0; i < vipTableSize; ++i)
	{
		int num;
		cin >> num;
		tables[num - 1].tag = Vip;
	}
	sort(players.begin(), players.end());
	for (auto && table : tables)
		if (table.tag == Vip)vipTables.push_back(table);
}
int idx = 0;
template<typename C>
Table& MinTable(int time,C& tables)
{
	auto temp = &static_cast<Table&>(tables.front());
	for (Table& table : tables)
	{
		if (table.endTime < time)return table;
		if (table.endTime < temp->endTime)temp = &table;
	}
	return *temp;
}
Table& GetTable(int time)
{
	return MinTable(time, tables);
}
Table& GetTableForVip(int time)
{
	auto& table = MinTable(time,vipTables);
	if (table.endTime > time)return GetTable(time);
	return table;
}
list<Player*> queue;
void Register(Player& player, Table& table)
{
	int time = max(player.arrivingTime, table.endTime);
	player.servingTime = time;
	table.endTime = time + player.playingTime;
	table.servePlayerSize++;
}
Player& MatchInQueue(Table& table)
{
	auto pos = queue.begin();
	if(table.tag==Vip)
	{
		pos = find_if(queue.begin(), queue.end(), 
			[](Player* player) { return player->tag == Vip; });
		if (pos == queue.end())pos = queue.begin();
	}
	auto player = *pos;
	queue.erase(pos);
	return *player;
}
void EventLoop()
{
	while (idx<N||!queue.empty())
	{
		if(GetTable(players[idx].arrivingTime).endTime<=players[idx].arrivingTime&&queue.empty())
		{
			if (players[idx].tag == Vip)Register(players[idx], GetTableForVip(players[idx].arrivingTime));
			else Register(players[idx], GetTable(players[idx].arrivingTime));
			idx++;
		}
		else
		{
			while (idx<N&&GetTable(players[idx].arrivingTime).endTime>players[idx].arrivingTime)
			{
				queue.push_back(&players[idx]);
				idx++;
			}
			auto& table = GetTable(players[idx-1].arrivingTime);
			if(table.endTime>=21*3600)break;
			Register(MatchInQueue(table), table);
		}
	}
}
void Output()
{
	sort(players.begin(), players.end(), 
		[](const Player& lhs, const Player& rhs) { return lhs.servingTime < rhs.servingTime; });
	for (auto && player : players)
		if(player.servingTime>0)player.Print();
	cout << tables.front().servePlayerSize;
	for (int i = 1; i < tables.size(); ++i)
		cout <<" "<< tables[i].servePlayerSize;
}
int main()
{
	Prepare();
	EventLoop();
	Output();
}
