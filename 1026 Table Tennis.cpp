#define   _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;
struct Table
{
    bool isVip=false;
    int servedSize=0;
    int availingTime=8*60*60;
};

struct Player
{
    bool isVip = false;
    int arrivingTime;
    int playingDuration;
    int playingTime;
    Player(int arriving,int duration,bool isVip):arrivingTime(arriving),playingDuration(duration),isVip(isVip){}
};
void PrintTime(int t)
{
    printf("%02d:%02d:%02d ", t / 60 / 60, t / 60 % 60, t % 60);
}
int main(int argc, char* argv[])
{
    int playerSize;
    cin >> playerSize;
    list<Player> players;
    list<decltype(players)::iterator>vipPlayerIters ;
    for (int i = 0; i < playerSize; ++i)
    {
        int hh, mm, ss, playingDuraion, isVip;
        scanf("%d:%d:%d%d%d", &hh, &mm, &ss, &playingDuraion, &isVip);
        playingDuraion = min(playingDuraion, 120);
        players.emplace_back((hh * 60 + mm) * 60 + ss, playingDuraion * 60, isVip);
        if (isVip)vipPlayerIters.push_back(--players.end());
    }
    players.sort([](Player lhs, Player rhs) { return lhs.arrivingTime < rhs.arrivingTime; });
    vipPlayerIters.sort([](auto lhs, auto rhs) { return lhs->arrivingTime < rhs->arrivingTime; });
    int tableSize, vipTableSize;
    cin >> tableSize >> vipTableSize;
    vector<Table> tables(tableSize);
    vector<Table*> vipTablePtrs;
    for (int i = 0; i < vipTableSize; ++i)
    {
        int idx;
        cin >> idx;
        tables[idx - 1].isVip = true;
        vipTablePtrs.push_back(&tables[idx - 1]);
    }
    vector<Player> orderBySevering;
    for (auto iter = players.begin(); iter != players.end(); )
    {
        auto player = *iter;
        auto tablePtr = &*min_element(tables.begin(), tables.end(),
            [](Table lhs, Table rhs) { return lhs.availingTime < rhs.availingTime; });
        bool hasSkiped = false;
        if(player.isVip)
        {
            vipPlayerIters.pop_front();
            if(!tablePtr->isVip&&!vipTablePtrs.empty())
            {
                auto vipTablePtr = *min_element(vipTablePtrs.begin(), vipTablePtrs.end(),
                    [](Table* lhs, Table* rhs) { return lhs->availingTime < rhs->availingTime; });
                if (vipTablePtr->availingTime <=player.arrivingTime)tablePtr = vipTablePtr;
            }
        }
        else if (tablePtr->isVip && !vipPlayerIters.empty())
        {
            if (vipPlayerIters.front()->arrivingTime <= tablePtr->availingTime)
            {
                player = *vipPlayerIters.front();
                players.erase(vipPlayerIters.front());
                vipPlayerIters.pop_front();
                hasSkiped = true;
            }
        }
        player.playingTime = max(tablePtr->availingTime, player.arrivingTime);
        if (player.playingTime>=21 * 60 * 60)break;
        tablePtr->availingTime = player.playingDuration + player.playingTime;
        tablePtr->servedSize++;
        orderBySevering.push_back(player);
        if (!hasSkiped)++iter;
    }
    for (auto player : orderBySevering)
    {
        PrintTime(player.arrivingTime);
        PrintTime(player.playingTime);
        cout << (int)round((player.playingTime - player.arrivingTime) / 60.0)<<'\n';
    }
    cout << tables.front().servedSize;
    for (int i = 1; i < tables.size(); ++i)cout <<" "<< tables[i].servedSize;
}
